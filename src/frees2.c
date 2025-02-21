/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:13:57 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/21 10:48:46 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map_vars(t_map *map, int limit)
{
	if (map->heights)
		free_heights(map, limit);
	if (map->colors)
		free_colors(map, limit);
	if (map->pos2d)
		free_pos2d(map, limit);
	if (map->row_len)
		free(map->row_len);
}
