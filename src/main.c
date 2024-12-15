/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:18:40 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/15 19:28:10 by mniemaz          ###   ########.fr       */
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

	if (d.x > d.y)
	{
		error = 2 * d.y - d.x;
		while (print.x != pos2.x)
		{
			// __builtin_printf("ici %d %d %p\n", print.x, print.y,
			// all->img.img);
			my_mlx_pixel_put(&all->img, print.x, print.y, 0x00FF0000);
			if (error > 0)
			{
				inc_or_decrease(pos1.y < pos2.y, &print.y);
				error -= 2 * d.x;
			}
			error += 2 * d.y;
			inc_or_decrease(pos1.x < pos2.x, &print.x);
		}
	}
	else
	{
		error = 2 * d.x - d.y;
		while (print.y != pos2.y)
		{
			// __builtin_printf("%d %d\n", print.x, print.y);
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
}

int	main(void)
{
	t_all all;

	all.vars.mlx = mlx_init();
	all.vars.win = mlx_new_window(all.vars.mlx, WIN_SIZE_X, WIN_SIZE_Y,
			"Hello world!");
	all.img.img = mlx_new_image(all.vars.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	all.img.addr = mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel,
			&all.img.line_length, &all.img.endian);

	__builtin_printf("img.addr: %p, bits_per_pixel: %d, line_length: %d\n",
		all.img.addr, all.img.bits_per_pixel, all.img.line_length);

	// int size = WIN_SIZE_Y / 2;

	// print_square(&all.img, CENTER_X - size / 2, CENTER_Y - size / 2, size,
	// 	0x00FF0000);
	t_pos pos1;
	t_pos pos2;

	pos1.x = CENTER_X;
	pos1.y = CENTER_Y;
	pos2.x = CENTER_X + 200;
	pos2.y = CENTER_Y - 500;
	print_square(&all.img, pos1.x - 5, pos1.y - 5, 10, 0x00FF0000);
	print_square(&all.img, pos2.x - 5, pos2.y - 5, 10, 0x00FF0000);
	print_line(&all, pos1, pos2);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	mlx_key_hook(all.vars.win, key_hook_func, &all);
	mlx_mouse_hook(all.vars.win, mouse_hook_func, &all);
	mlx_loop(all.vars.mlx);
}