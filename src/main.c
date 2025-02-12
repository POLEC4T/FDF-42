/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:18:40 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/12 12:28:36 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// int		pixel;
	(void)dst;
	(void)color;
	if (x < 0 || x >= WIN_SIZE_X || y < 0 || y >= WIN_SIZE_Y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// __builtin_printf("[%d,%d] \n", x - CENTER_X, y - CENTER_Y);
	*(unsigned int *)dst = color;
}

void	inc_or_decrease(int condition, int *val)
{
	if (condition)
		(*val)++;
	else
		(*val)--;
}

void	bresenham_line(t_pos pos1, t_pos pos2, t_all *all)
{
	int	dx;
	int	dy;
	int	err;
	int	temp_err;

	dx = abs(pos2.x - pos1.x);
	dy = abs(pos2.y - pos1.y);
	err = dx - dy;
	while (1)
	{
		my_mlx_pixel_put(&all->img, pos1.x, pos1.y, 0xFFFFFF);
		if (pos1.x == pos2.x && pos1.y == pos2.y)
			break ;
		temp_err = 2 * err;
		if (temp_err > -dy)
		{
			err -= dy;
			inc_or_decrease(pos1.x < pos2.x, &pos1.x);
		}
		if (temp_err < dx)
		{
			err += dx;
			inc_or_decrease(pos1.y < pos2.y, &pos1.y);
		}
	}
}

t_all	my_init_mlx(void)
{
	t_all	all;

	all.vars.mlx = mlx_init();
	all.vars.win = mlx_new_window(all.vars.mlx, WIN_SIZE_X, WIN_SIZE_Y,
			"Hello world!");
	all.img.img = mlx_new_image(all.vars.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	all.img.addr = mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel,
			&all.img.line_length, &all.img.endian);
	return (all);
}


void	print_map_terminal(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->nb_rows)
	{
		col = 0;
		while (col < map->nb_cols)
		{
			__builtin_printf("%d ", map->heights[row][col]);
			col++;
		}
		__builtin_printf("\n");
		row++;
	}
}

void	end_process(t_all *all, enum free_mode free_mode, enum msg_ids msg_id)
{
	if (free_mode == FREE_MLX)
		free_mlx(all);
	else if (free_mode == FREE_HEIGHTS)
		free_heights(&all->map, all->map.nb_rows);
	else if (free_mode == FREE_POS2D)
		free_pos2d(&all->map, all->map.nb_rows);
	else if (free_mode == FREE_HEIGHTS_MLX)
	{
		free_mlx(all);
		free_heights(&all->map, all->map.nb_rows);
	}
	else if (free_mode == FREE_ALL)
	{
		free_mlx(all);
		free_heights(&all->map, all->map.nb_rows);
		free_pos2d(&all->map, all->map.nb_rows);
	}
	print_msg(msg_id);
	exit_acc_to_msg_id(msg_id);
}

t_pos	iso_proj(int x, int y, int z, t_map *map)
{
	t_pos	pos2d;

	// Calcul des coordonnées isométriques
	pos2d.x = (x - y) * map->step;
	pos2d.y = (x + y) * (map->step / 2) - z * 20;
	return (pos2d);
}

t_pos	iso_proj2(int x, int y, int z, t_map *map)
{
	t_pos	pos2d;

	(void)map;
	pos2d.x = (x - y) * 0.9; // 0.9 = cos(PI / 6) // cos(PI / 6) * x - cos(PI / 6) * y
	pos2d.y = ((x + y) * 0.5 - z * 3); // 0.5 = sin(PI / 6)
	return (pos2d);
}

void	z_rotate(t_pos *pos, double angle, t_all *all)
{
	double	x;
	double	y;
	t_pos	dist_to_origin;

	(void)all;
	dist_to_origin.x = CENTER_X;
	dist_to_origin.y = CENTER_Y;
	x = pos->x - dist_to_origin.x;
	y = pos->y - dist_to_origin.y;
	pos->x = x * cos(angle) - y * sin(angle) + dist_to_origin.x;
	pos->y = x * sin(angle) + y * cos(angle) + dist_to_origin.y;
}



void	x_rotate(t_pos *pos, int *height, double angle, t_all *all)
{
	double	y;
	double	z;
	t_pos	dist_to_origin;

	(void)all;
	dist_to_origin.x = CENTER_X;
	dist_to_origin.y = CENTER_Y;
	y = pos->y - dist_to_origin.y;
	z = *height * all->map.height_multiplier;
	pos->y = y * cos(angle) - z * sin(angle) + dist_to_origin.y;
	*height = y * sin(angle) + z * cos(angle);
}

void	draw_lines(t_all *all)
{
	int		row;
	int		col;

	row = 0;
	printf("My map:");
	while (row < all->map.nb_rows)
	{
		col = 0;
		printf("\n");
		while (col < all->map.nb_cols)
		{
			printf("%d ", all->map.heights[row][col]);
			if (col != all->map.nb_cols - 1)
				bresenham_line(all->map.pos2d[row][col], all->map.pos2d[row][col + 1], all);
			if (row != all->map.nb_rows - 1)
				bresenham_line(all->map.pos2d[row][col], all->map.pos2d[row + 1][col], all);
			col++;
		}
		row++;
	}
}

void print_square(t_all *all, t_pos pos, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(&all->img, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}

void	prepare_map(t_all *all)
{
	int row;
	int col;
	// t_pos pos1;
	double z_angle;
	double x_angle;

	row = 0;
	x_angle = 3.141592 / 6;
	z_angle = 3.141592 / 6;
	while (row < all->map.nb_rows)
	{
		col = 0;
		while (col < all->map.nb_cols)
		{
			all->map.pos2d[row][col].x = all->map.origin.x + col * all->map.step;
			all->map.pos2d[row][col].y = all->map.origin.y + row * all->map.step;
			z_rotate(&all->map.pos2d[row][col], z_angle, all);
			x_rotate(&all->map.pos2d[row][col], &all->map.heights[row][col], x_angle, all);
			col++;
		}
		row++;
	}
}

int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	display_plan(t_all *all)
{
	
	int step_x;
	int step_y;

	step_x = WIN_SIZE_X / all->map.nb_cols;
	step_y = WIN_SIZE_Y / all->map.nb_rows;

	all->map.step = min(step_x, step_y) * 0.7;
	all->map.origin.x = CENTER_X - (all->map.nb_cols * all->map.step) / 2 + all->map.step / 2;
	all->map.origin.y = CENTER_Y - (all->map.nb_rows * all->map.step) / 2 + all->map.step / 2;
	all->map.height_multiplier = 5;
	// print_square(all, all->map.origin, 10, 0xFF0000);
	prepare_map(all);
	draw_lines(all);
	return (0);
}

// infos :
// - taille de la fenetre : 1920 x 1080
// - le nombre de colonnes et de lignes de la map

int	my_loop(t_all *all)
{
	__builtin_printf("loop\n");
	display_plan(all);
	return (0);
}



int	main(int ac, char **av)
{
	t_all	all;
	t_map	map;
	t_pos	pos1;
	t_pos	pos2;

	(void)**av;
	(void)ac;
	if (ac != 2)
	{
		if (ac == 1)
			print_msg(ERROR_NO_MAP);
		else
			print_msg(ERROR_TOO_MANY_ARGS);
		exit(1);
	}
	check_map(av[1], &map);
	init_map(&map, av[1]);
	all = my_init_mlx();
	all.map = map;
	pos1.x = CENTER_X;
	pos1.y = CENTER_Y;
	pos2.x = CENTER_X + 60;
	pos2.y = CENTER_Y - 50;
	display_plan(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	mlx_key_hook(all.vars.win, key_hook_func, &all);
	mlx_loop(all.vars.mlx);
}