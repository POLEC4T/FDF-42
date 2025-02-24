/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/21 17:17:55 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief Process the Bresenham calculation (used in bresenham algorithm)
 */
static int	process_bresenham_calc(t_line *line, t_pos d, int err)
{
	int	temp_err;

	temp_err = 2 * err;
	if (temp_err > -d.y)
	{
		err -= d.y;
		if (line->from.x < line->to.x)
			line->from.x++;
		else
			line->from.x--;
	}
	if (temp_err < d.x)
	{
		err += d.x;
		if (line->from.y < line->to.y)
			line->from.y++;
		else
			line->from.y--;
	}
	return (err);
}

/**
 * @returns the number of pixels that would be drawn by the
 * Bresenham algorithm for a given line
 */
int	bresenham_line_counter(t_line line)
{
	t_pos	d;
	int		err;
	int		counter;

	counter = 0;
	d.x = ABS((line.to.x - line.from.x));
	d.y = ABS((line.to.y - line.from.y));
	err = d.x - d.y;
	while (1)
	{
		counter++;
		if (line.from.x == line.to.x && line.from.y == line.to.y)
			break ;
		err = process_bresenham_calc(&line, d, err);
	}
	return (counter);
}

/**
 * @brief Draw a line between two cells of the map using the Bresenham algorithm
 */
void	bresenham_line(t_param *param, t_grid_pos cell_from, t_grid_pos cell_to)
{
	t_pos			d;
	int				err;
	int				i;
	t_line			line;
	t_step_colors	step;

	line.from = param->map.pos2d[cell_from.row][cell_from.col];
	line.to = param->map.pos2d[cell_to.row][cell_to.col];
	step = calc_step_colors(param, cell_from, cell_to);
	d.x = ABS((line.to.x - line.from.x));
	d.y = ABS((line.to.y - line.from.y));
	err = d.x - d.y;
	i = 0;
	while (1)
	{
		my_mlx_pixel_put(&param->img, line.from, rgb_to_int(calc_color(param,
					cell_from, i, step)));
		if (line.from.x == line.to.x && line.from.y == line.to.y)
			break ;
		err = process_bresenham_calc(&line, d, err);
		i++;
	}
}
