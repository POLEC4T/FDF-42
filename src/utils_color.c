/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:24:38 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/18 10:57:40 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) + (color.g << 8) + color.b);
}

t_color	int_to_rgb(int color)
{
	t_color	rgb;

	rgb.r = (color & 0xFF0000) >> 16;
	rgb.g = (color & 0xFF00) >> 8;
	rgb.b = color & 0xFF;
	return (rgb);
}

/**
 * @brief Calculate the step for each color (r, g, b) between two points
 * @example if (nb_pixels = 500, cell_1.r = 10, cell_2.r = 20)
 * then -> step.r = 20 - 10 / 500 = 0.02
 * which means that the red will be incremented by 0.02 for each pixel
 */
t_step_colors	calc_step_colors(t_param *param, t_grid_pos pos1,
		t_grid_pos pos2)
{
	int				nb_pixels;
	t_step_colors	step;
	t_line			line;

	line.from = param->map.pos2d[pos1.row][pos1.col];
	line.to = param->map.pos2d[pos2.row][pos2.col];
	nb_pixels = bresenham_line_counter(line);
	step.r = ((float)(param->map.colors[pos2.row][pos2.col].r
				- param->map.colors[pos1.row][pos1.col].r) / nb_pixels);
	step.g = ((float)(param->map.colors[pos2.row][pos2.col].g
				- param->map.colors[pos1.row][pos1.col].g) / nb_pixels);
	step.b = ((float)(param->map.colors[pos2.row][pos2.col].b
				- param->map.colors[pos1.row][pos1.col].b) / nb_pixels);
	return (step);
}

/**
 * @brief Calculate the color of a pixel between two points
 * @param i the number of pixels already drawn
 * @param step_colors the step for each color (r, g, b) between two points
 */
t_color	calc_color(t_param *param, t_grid_pos pos1, int i,
		t_step_colors step_colors)
{
	t_color	color;

	color.r = param->map.colors[pos1.row][pos1.col].r + step_colors.r * i;
	color.g = param->map.colors[pos1.row][pos1.col].g + step_colors.g * i;
	color.b = param->map.colors[pos1.row][pos1.col].b + step_colors.b * i;
	return (color);
}
