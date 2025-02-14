/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 18:58:53 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	inc_or_decrease(int condition, int *val)
{
	if (condition)
		(*val)++;
	else
		(*val)--;
}

void	process_bresenham_calc(t_line *line, t_pos d, int *err)
{
	int	temp_err;

	temp_err = 2 * *err;
	if (temp_err > -d.y)
	{
		*err -= d.y;
		inc_or_decrease(line->from.x < line->to.x, &line->from.x);
	}
	if (temp_err < d.x)
	{
		*err += d.x;
		inc_or_decrease(line->from.y < line->to.y, &line->from.y);
	}
}

int	bresenham_line_counter(t_line line)
{
	t_pos	d;
	int		err;
	int		counter;

	counter = 0;
	d.x = abs(line.to.x - line.from.x);
	d.y = abs(line.to.y - line.from.y);
	err = d.x - d.y;
	while (1)
	{
		counter++;
		if (line.from.x == line.to.x && line.from.y == line.to.y)
			break ;
		process_bresenham_calc(&line, d, &err);
	}
	return (counter);
}

void	bresenham_line(t_all *all, t_grid_pos cell_from, t_grid_pos cell_to)
{
	t_pos			d;
	int				err;
	int				i;
	t_line			line;
	t_step_colors	step;

	line.from = all->map.pos2d[cell_from.row][cell_from.col];
	line.to = all->map.pos2d[cell_to.row][cell_to.col];
	step = calc_step_colors(all, cell_from, cell_to);
	d.x = abs(line.to.x - line.from.x);
	d.y = abs(line.to.y - line.from.y);
	err = d.x - d.y;
	i = 0;
	while (1)
	{
		my_mlx_pixel_put(&all->img, line.from, rgb_to_int(calc_color(all,
					cell_from, i, step)));
		if (line.from.x == line.to.x && line.from.y == line.to.y)
			break ;
		process_bresenham_calc(&line, d, &err);
		i++;
	}
}
