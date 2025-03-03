/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_rotates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:01:28 by mniemaz           #+#    #+#             */
/*   Updated: 2025/03/03 10:14:25 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	z_rotate(t_pos *pos, double angle)
{
	double	x;
	double	y;
	t_pos	dist_to_origin;

	dist_to_origin.x = WIN_SIZE_X / 2;
	dist_to_origin.y = WIN_SIZE_Y / 2;
	x = pos->x - dist_to_origin.x;
	y = pos->y - dist_to_origin.y;
	pos->x = x * cos(angle) - y * sin(angle) + dist_to_origin.x;
	pos->y = x * sin(angle) + y * cos(angle) + dist_to_origin.y;
}

void	x_rotate(t_pos *pos, int *height, double angle, t_param *param)
{
	double	y;
	double	z;
	t_pos	dist_to_origin;

	dist_to_origin.x = WIN_SIZE_X / 2;
	dist_to_origin.y = WIN_SIZE_Y / 2;
	if ((long)*height * param->map.height_multiplier > (long)INT_MAX
		|| (long)*height * param->map.height_multiplier < (long)INT_MIN)
		z = *height;
	else
		z = *height * param->map.height_multiplier;
	y = pos->y - dist_to_origin.y;
	pos->y = y * cos(angle) - z * sin(angle) + dist_to_origin.y;
	*height = y * sin(angle) + z * cos(angle);
}
