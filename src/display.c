/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:55:26 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/19 17:13:54 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief calls the bresenham_line function for each cell of the map
 */
static void	draw_lines(t_param *param)
{
	t_grid_pos	cell;
	t_grid_pos	bottom_cell;
	t_grid_pos	right_cell;

	cell.row = 0;
	while (cell.row < param->map.nb_rows)
	{
		cell.col = 0;
		while (cell.col < param->map.row_len[cell.row])
		{
			right_cell = (t_grid_pos){cell.row, cell.col + 1};
			bottom_cell = (t_grid_pos){cell.row + 1, cell.col};
			if (cell.col < param->map.row_len[cell.row] - 1)
			{
				bresenham_line(param, cell, right_cell);
			}
			if (cell.row != param->map.nb_rows - 1
				&& cell.col < param->map.row_len[cell.row + 1])
				bresenham_line(param, cell, bottom_cell);
			cell.col++;
		}
		cell.row++;
	}
}

static void	prepare_map_2d(t_param *param)
{
	int	row;
	int	col;

	row = 0;
	while (row < param->map.nb_rows)
	{
		col = 0;
		while (col < param->map.row_len[row])
		{
			param->map.pos2d[row][col].x = param->map.origin.x + col
				* param->map.step;
			param->map.pos2d[row][col].y = param->map.origin.y + row
				* param->map.step;
			z_rotate(&param->map.pos2d[row][col], M_PI / 6, param);
			x_rotate(&param->map.pos2d[row][col], &param->map.heights[row][col],
				M_PI / 4, param);
			col++;
		}
		row++;
	}
}

static void	setup_map_params(t_param *param)
{
	int	step_x;
	int	step_y;
	int	max_row_len;

	max_row_len = get_max_row_len(&param->map);
	step_x = WIN_SIZE_X / max_row_len;
	step_y = WIN_SIZE_Y / param->map.nb_rows;
	if (step_x < step_y)
		param->map.step = step_x * 0.7;
	else
		param->map.step = step_y * 0.7;
	param->map.origin.x = WIN_SIZE_X / 2 - (max_row_len * param->map.step) / 2
		+ param->map.step / 2;
	param->map.origin.y = WIN_SIZE_Y / 2 - (param->map.nb_rows
			* param->map.step) / 2 + param->map.step / 2;
	param->map.height_multiplier = 10;
}

int	display_plan(t_param *param)
{
	setup_map_params(param);
	prepare_map_2d(param);
	draw_lines(param);
	return (0);
}
