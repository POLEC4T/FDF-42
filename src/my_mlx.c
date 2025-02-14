/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:48:41 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 18:48:54 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, t_pos pos, int color)
{
	char	*dst;

	if (pos.x < 0 || pos.x >= WIN_SIZE_X || pos.y < 0 || pos.y >= WIN_SIZE_Y)
		return ;
	dst = data->addr + (pos.y * data->line_length + pos.x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_init_mlx(t_all *all)
{
	all->vars.mlx = mlx_init();
	all->vars.win = mlx_new_window(all->vars.mlx, WIN_SIZE_X, WIN_SIZE_Y,
			"Hello world!");
	all->img.img = mlx_new_image(all->vars.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
			&all->img.line_length, &all->img.endian);
}
