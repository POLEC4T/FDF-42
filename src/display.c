/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:55:26 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 19:14:12 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	draw_lines(t_all *all)
{
	t_grid_pos	cell;

	cell.row = 0;
	while (cell.row < all->map.nb_rows)
	{
		cell.col = 0;
		while (cell.col < all->map.nb_cols)
		{
			if (cell.col != all->map.nb_cols - 1)
				bresenham_line(all, cell, (t_grid_pos){cell.row, cell.col + 1});
			if (cell.row != all->map.nb_rows - 1)
				bresenham_line(all, cell, (t_grid_pos){cell.row + 1, cell.col});
			cell.col++;
		}
		cell.row++;
	}
}

static void	prepare_map_2d(t_all *all)
{
	t_grid_pos	cell;
	double		z_angle;
	double		x_angle;

	cell.row = 0;
	x_angle = M_PI / 6;
	z_angle = M_PI / 6;
	while (cell.row < all->map.nb_rows)
	{
		cell.col = 0;
		while (cell.col < all->map.nb_cols)
		{
			all->map.pos2d[cell.row][cell.col].x = all->map.origin.x + cell.col
				* all->map.step;
			all->map.pos2d[cell.row][cell.col].y = all->map.origin.y + cell.row
				* all->map.step;
			z_rotate(&all->map.pos2d[cell.row][cell.col], z_angle, all);
			x_rotate(&all->map.pos2d[cell.row][cell.col],
				&all->map.heights[cell.row][cell.col], x_angle, all);
			cell.col++;
		}
		cell.row++;
	}
}

static void	setup_map_params(t_all *all)
{
	int	step_x;
	int	step_y;

	step_x = WIN_SIZE_X / all->map.nb_cols;
	step_y = WIN_SIZE_Y / all->map.nb_rows;
	if (step_x < step_y)
		all->map.step = step_x * 0.7;
	else
		all->map.step = step_y * 0.7;
	all->map.origin.x = WIN_SIZE_X / 2 - (all->map.nb_cols * all->map.step) / 2
		+ all->map.step / 2;
	all->map.origin.y = WIN_SIZE_Y / 2 - (all->map.nb_rows * all->map.step) / 2
		+ all->map.step / 2;
	all->map.height_multiplier = 10;
}

int	display_plan(t_all *all)
{
	setup_map_params(all);
	prepare_map_2d(all);
	draw_lines(all);
	return (0);
}
