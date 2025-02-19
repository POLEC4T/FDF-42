/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:13 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/19 19:40:17 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	allocate_map_vars(t_map *map)
{
	map->heights = ft_calloc(sizeof(int *), map->nb_rows);
	if (!map->heights)
		exit_perror("Error alloc");
	map->colors = ft_calloc(sizeof(t_color *), map->nb_rows);
	if (!map->colors)
	{
		free(map->heights);
		exit_perror("Error alloc");
	}
	map->pos2d = ft_calloc(sizeof(t_pos *), map->nb_rows);
	if (!map->pos2d)
	{
		free(map->colors);
		free(map->heights);
		exit_perror("Error alloc");
	}
	map->row_len = ft_calloc(sizeof(int), map->nb_rows);
	if (!map->row_len)
	{
		free(map->pos2d);
		free(map->colors);
		free(map->heights);
		exit_perror("Error alloc");
	}
}

void	allocate_map_lines(t_map *map, char **str_line_elems, char **lines,
		int row_elems)
{
	map->heights[row_elems] = ft_calloc((strtab_len_valid_elems(str_line_elems)),
			sizeof(int));
	if (!map->heights[row_elems])
		exit_alloc_error(lines, str_line_elems, map, row_elems);
	map->colors[row_elems] = ft_calloc(strtab_len_valid_elems(str_line_elems),
			sizeof(t_color));
	if (!map->colors[row_elems])
	{
		free(map->heights[row_elems]);
		exit_alloc_error(lines, str_line_elems, map, row_elems);
	}
	map->pos2d[row_elems] = ft_calloc(strtab_len_valid_elems(str_line_elems),
			sizeof(t_pos));
	if (!map->pos2d[row_elems])
	{
		free(map->colors[row_elems]);
		free(map->heights[row_elems]);
		exit_alloc_error(lines, str_line_elems, map, row_elems);
	}
}
