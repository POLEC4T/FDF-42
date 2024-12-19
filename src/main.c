/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:18:40 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/19 23:26:55 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_SIZE_X || y < 0 || y >= WIN_SIZE_Y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_square(t_data *img, int x, int y, int size, int color)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	inc_or_decrease(int condition, int *val)
{
	if (condition)
		(*val)++;
	else
		(*val)--;
}

void	print_line(t_all *all, t_pos pos1, t_pos pos2)
{
	t_pos	d;
	t_pos	print;
	int		error;

	d.x = abs(pos2.x - pos1.x);
	d.y = abs(pos2.y - pos1.y);
	print.x = pos1.x;
	print.y = pos1.y;
	error = 2 * d.y - d.x;
	while (d.x > d.y && print.x != pos2.x)
	{
		my_mlx_pixel_put(&all->img, print.x, print.y, 0x00FF0000);
		if (error > 0)
		{
			inc_or_decrease(pos1.y < pos2.y, &print.y);
			error -= 2 * d.x;
		}
		error += 2 * d.y;
		inc_or_decrease(pos1.x < pos2.x, &print.x);
	}
	error = 2 * d.x - d.y;
	while (d.x <= d.y && print.y != pos2.y)
	{
		my_mlx_pixel_put(&all->img, print.x, print.y, 0x00FF0000);
		if (error > 0)
		{
			inc_or_decrease(pos1.x < pos2.x, &print.x);
			error -= 2 * d.y;
		}
		error += 2 * d.x;
		inc_or_decrease(pos1.y < pos2.y, &print.y);
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

void	init_map(t_all *all, char *filename)
{
	int		fd;
	char	*line;
	char	**str_values;
	int		row_values;
	int		i_str_values;
	int		col_values;

	all->map.values = malloc(sizeof(int *) * all->map.nb_rows);
	if (!all->map.values)
		end_process(all, FREE_MLX, ERROR_MALLOC_BROKE);
	all->map.row_lengths = malloc(sizeof(int) * all->map.nb_rows);
	if (!all->map.row_lengths)
		end_process(all, FREE_MLX, ERROR_MALLOC_BROKE);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	row_values = 0;
	while (line)
	{
		str_values = ft_split(line, " \n");
		all->map.values[row_values] = malloc(strtab_len_valid_nbs(str_values)
				* sizeof(int));
		i_str_values = 0;
		col_values = 0;
		while (str_values[i_str_values])
		{
			all->map.values[row_values][col_values] = ft_atoi(str_values[i_str_values]);
			col_values++;
			i_str_values++;
		}
		all->map.row_lengths[row_values] = col_values;
		free(line);
		line = get_next_line(fd);
		free_tab_str(str_values);
		row_values++;
	}
}

void	print_map_terminal(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->nb_rows)
	{
		col = 0;
		while (col < map->len_biggest_row)
		{
			__builtin_printf("%d ", map->values[row][col]);
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
	else if (free_mode == FREE_MAP)
		free_map_content(all);
	else if (free_mode == FREE_ALL)
	{
		free_mlx(all);
		free_map_content(all);
	}
	print_msg(msg_id);
	exit_acc_to_msg_id(msg_id);
}

void	values_wlk(t_all *all)
{
	int	row;
	int	col;

	row = 0;
	__builtin_printf("My map:\n");
	while (row < all->map.nb_rows)
	{
		col = 0;
		while (col < all->map.row_lengths[row])
		{
			__builtin_printf("%d ", all->map.values[row][col]);
			col++;
		}
		__builtin_printf("\n");
		row++;
	}
	__builtin_printf("\n");
}

int	display_plan(t_all *all)
{
	// t_line	*lines;
	all->map.origin.x = CENTER_X;
	all->map.origin.y = 100;
	all->map.x_step = 40;
	all->map.y_step = 30;
	values_wlk(all);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;
	t_map	map;

	// t_pos	pos1;
	// t_pos	pos2;
	(void)**av;
	(void)ac;
	if (ac != 2)
		return (0);
	check_map(av[1], &map);
	all = my_init_mlx();
	all.map = map;
	init_map(&all, av[1]);
	// pos1.x = CENTER_X;
	// pos1.y = CENTER_Y;
	// pos2.x = CENTER_X + 500;
	// pos2.y = CENTER_Y + 500;
	// print_square(&all.img, pos1.x - 5, pos1.y - 5, 10, 0x00FF0000);
	// print_square(&all.img, pos2.x - 5, pos2.y - 5, 10, 0x00FF0000);
	// print_line(&all, pos1, pos2);
	// __builtin_printf("val:%d \n", map.values[1][1]);
	display_plan(&all);
	print_map_terminal(&all.map);
	// mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	// mlx_mouse_hook(all.vars.win, mouse_hook_func, &all);
	mlx_key_hook(all.vars.win, key_hook_func, &all);
	mlx_loop(all.vars.mlx);
}

// prochaine etape,
// FIX LEAKS