/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:18:40 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/17 22:09:40 by mniemaz          ###   ########.fr       */
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

t_all	init_mlx(void)
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

void	init_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	char	**str_values;
	int		i_values;
	int		i_str_values;
	int		j_values;

	map->nb_rows = 0;
	set_map_sizes(filename, map);
	map->values = malloc(sizeof(int *) * map->nb_rows);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	i_values = 0;
	while (line)
	{
		map->values[i_values] = malloc(map->len_biggest_row * sizeof(int));
		str_values = ft_split(line, ' ');
		i_str_values = 0;
		j_values = 0;
		while (str_values[i_str_values])
		{
			if (contains_digit(str_values[i_str_values]))
				map->values[i_values][j_values] = ft_atoi(str_values[i_str_values]);
			i_str_values++;
			j_values++;
		}
		i_values++;
		free(line);
		line = get_next_line(fd);
		free_tab_str(str_values);
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

int	main(int ac, char **av)
{
	t_map	map;
	t_all	all;

	// t_pos	pos1;
	// t_pos	pos2;
	if (ac != 2)
		return (0);
	all = init_mlx();
	// pos1.x = CENTER_X;
	// pos1.y = CENTER_Y;
	// pos2.x = CENTER_X + 500;
	// pos2.y = CENTER_Y + 500;
	// print_square(&all.img, pos1.x - 5, pos1.y - 5, 10, 0x00FF0000);
	// print_square(&all.img, pos2.x - 5, pos2.y - 5, 10, 0x00FF0000);
	// print_line(&all, pos1, pos2);
	init_map(&map, av[1]);
	// __builtin_printf("val:%d \n", map.values[1][1]);
	print_map_terminal(&map);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	mlx_key_hook(all.vars.win, key_hook_func, &all);
	// mlx_mouse_hook(all.vars.win, mouse_hook_func, &all);
	mlx_loop(all.vars.mlx);
}

// prochaine etape,
// FIX LEAKS