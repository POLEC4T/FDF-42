/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:48:41 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/19 11:17:45 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief Puts a pixel in the image
 */
void	my_mlx_pixel_put(t_data *data, t_pos pos, int color)
{
	char	*dst;

	if (pos.x < 0 || pos.x >= WIN_SIZE_X || pos.y < 0 || pos.y >= WIN_SIZE_Y)
		return ;
	dst = data->addr + (pos.y * data->line_length + pos.x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_init_mlx(t_param *param)
{
	param->vars.mlx = mlx_init();
	param->vars.win = mlx_new_window(param->vars.mlx, WIN_SIZE_X, WIN_SIZE_Y,
			"FDF");
	param->img.img = mlx_new_image(param->vars.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	param->img.addr = mlx_get_data_addr(param->img.img,
			&param->img.bits_per_pixel, &param->img.line_length,
			&param->img.endian);
}
