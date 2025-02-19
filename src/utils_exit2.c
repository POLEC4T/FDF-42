/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:26:16 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/19 19:17:42 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	exit_perror(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	exit_alloc_error(char **lines, char **str_line_elems, t_map *map,
		int row_elems)
{
	
	if (lines)
		free_tab_str(lines);
	if (str_line_elems)
		free_tab_str(str_line_elems);
	if (map->heights)
		free_heights(map, row_elems);
	if (map->colors)
		free_colors(map, row_elems);
	if (map->pos2d)
		free_pos2d(map, row_elems);
	if (map->row_len)
		free(map->row_len);
	exit_perror("Error alloc");
}
