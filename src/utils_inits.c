/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:13 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 19:06:27 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	exit_alloc_error(char *line, char **str_line_elems, t_map *map,
		int row_elems)
{
	free(line);
	free_tab_str(str_line_elems);
	free_heights(map, row_elems);
	free_colors(map, row_elems);
	free_pos2d(map, row_elems);
	perror("Error alloc");
	exit(1);
}
