/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:26:16 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/21 10:47:03 by mniemaz          ###   ########.fr       */
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
	free_map_vars(map, row_elems);
	exit_perror("Error alloc");
}

void	exit_out_of_range_error(char **lines, char **str_line_elems, t_map *map,
		int row_elems)
{
	if (lines)
		free_tab_str(lines);
	if (str_line_elems)
		free_tab_str(str_line_elems);
	free_map_vars(map, row_elems);
	print_msg(ERROR_INV_MAP);
	exit(EXIT_FAILURE);
}
