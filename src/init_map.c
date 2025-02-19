/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:13 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/19 20:01:28 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @returns 0 if exit is needed (number out of range or alloc error)
 */
int	process_elem_set_map_vars(int i_str_line_elems, t_grid_pos elem,
	t_map *map, char **str_line_elems)
{
	char	**str_elem;
	int		is_number_out_of_range;

	is_number_out_of_range = 0;
	str_elem = ft_split(str_line_elems[i_str_line_elems], ",");
	if (!str_elem)
		return (0);
	if (strtab_len(str_elem) == 2)
	{
		map->heights[elem.row][elem.col] = ft_atoi_improved(str_elem[0],
				&is_number_out_of_range);
		map->colors[elem.row][elem.col] = int_to_rgb(ft_atoui_base(
					ft_str_toupper(str_elem[1]) + 2, "0123456789ABCDEF"));
	}
	else
	{
		map->heights[elem.row][elem.col] = ft_atoi_improved(
				str_line_elems[i_str_line_elems],
				&is_number_out_of_range);
		map->colors[elem.row][elem.col] = (t_color){255, 255, 255};
	}
	free_tab_str(str_elem);
	return (!is_number_out_of_range);
}

void	set_map_vars(t_map *map, char **str_line_elems, char **lines,
		int row_elems)
{
	int	i_str_line_elems;
	int	col_elems;
	int process_succeded;

	i_str_line_elems = -1;
	col_elems = 0;
	while (str_line_elems[++i_str_line_elems])
	{
		process_succeded = process_elem_set_map_vars(i_str_line_elems,
					(t_grid_pos){row_elems, col_elems}, map, str_line_elems);
		if (!process_succeded)
			exit_alloc_error(lines, str_line_elems, map, map->nb_rows);
		col_elems++;
	}
	map->row_len[row_elems] = col_elems;
}

void	process_init_line(t_map *map, char **lines, int row_elems)
{
	char	**str_line_elems;

	str_line_elems = ft_split(lines[row_elems], " \n");
	if (!str_line_elems)
		exit_alloc_error(lines, NULL, map, row_elems);
	allocate_map_lines(map, str_line_elems, lines, row_elems);
	set_map_vars(map, str_line_elems, lines, row_elems);
	free_tab_str(str_line_elems);
}

void	init_map(t_map *map, char *filename)
{
	int		fd;
	char	**lines;
	int		row_elems;

	allocate_map_vars(map);
	lines = malloc(sizeof(char *) * (map->nb_rows + 1));
	if (!lines)
		exit_perror("Error alloc");
	fd = open_map_file(filename);
	if (fd < 0)
		exit_perror("Error opening file");
	row_elems = 0;
	while (row_elems < map->nb_rows + 1)
	{
		lines[row_elems] = get_next_line(fd);
		row_elems++;
	}
	close(fd);
	row_elems = 0;
	while (lines[row_elems])
	{
		process_init_line(map, lines, row_elems);
		row_elems++;
	}
	free_tab_str(lines);
}
