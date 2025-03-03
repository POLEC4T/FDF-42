/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:48:41 by mniemaz           #+#    #+#             */
/*   Updated: 2025/03/03 10:21:24 by mniemaz          ###   ########.fr       */
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

static void	exit_mlx_error(t_param *param, int err_level)
{
	if (err_level >= 2)
		mlx_destroy_window(param->vars.mlx, param->vars.win);
	if (err_level >= 3)
		mlx_destroy_image(param->vars.mlx, param->img.img);
	if (err_level >= 1)
	{
		mlx_destroy_display(param->vars.mlx);
		free(param->vars.mlx);
	}
	free_map_vars(&param->map, param->map.nb_rows);
	exit_perror("Error mlx init");
}

void	my_init_mlx(t_param *param)
{
	param->vars.mlx = mlx_init();
	if (!param->vars.mlx)
		exit_mlx_error(param, 0);
	param->vars.win = mlx_new_window(param->vars.mlx, WIN_SIZE_X, WIN_SIZE_Y,
			"FDF - mniemaz");
	if (!param->vars.win)
		exit_mlx_error(param, 1);
	param->img.img = mlx_new_image(param->vars.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	if (!param->img.img)
		exit_mlx_error(param, 2);
	param->img.addr = mlx_get_data_addr(param->img.img,
			&param->img.bits_per_pixel, &param->img.line_length,
			&param->img.endian);
	if (!param->img.addr)
		exit_mlx_error(param, 3);
}
