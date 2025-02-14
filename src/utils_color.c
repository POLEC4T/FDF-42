/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:24:38 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 19:06:23 by mniemaz          ###   ########.fr       */
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

t_step_colors	calc_step_colors(t_all *all, t_grid_pos pos1, t_grid_pos pos2)
{
	int				nb_pixels;
	t_step_colors	step;
	t_line			line;

	line.from = all->map.pos2d[pos1.row][pos1.col];
	line.to = all->map.pos2d[pos2.row][pos2.col];
	nb_pixels = bresenham_line_counter(line);
	step.r = ((float)(all->map.colors[pos2.row][pos2.col].r
				- all->map.colors[pos1.row][pos1.col].r) / nb_pixels);
	step.g = ((float)(all->map.colors[pos2.row][pos2.col].g
				- all->map.colors[pos1.row][pos1.col].g) / nb_pixels);
	step.b = ((float)(all->map.colors[pos2.row][pos2.col].b
				- all->map.colors[pos1.row][pos1.col].b) / nb_pixels);
	return (step);
}

t_color	calc_color(t_all *all, t_grid_pos pos1, int i,
		t_step_colors step_colors)
{
	t_color	color;

	color.r = all->map.colors[pos1.row][pos1.col].r + step_colors.r * i;
	color.g = all->map.colors[pos1.row][pos1.col].g + step_colors.g * i;
	color.b = all->map.colors[pos1.row][pos1.col].b + step_colors.b * i;
	return (color);
}
