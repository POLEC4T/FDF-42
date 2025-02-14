/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:13 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 19:02:12 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	allocate_map_vars(t_map *map)
{
	map->heights = malloc(sizeof(int *) * map->nb_rows);
	if (!map->heights)
	{
		perror("Error alloc");
		exit(1);
	}
	map->colors = malloc(sizeof(t_color *) * map->nb_rows);
	if (!map->colors)
	{
		free(map->heights);
		perror("Error alloc");
		exit(1);
	}
	map->pos2d = malloc(sizeof(t_pos *) * map->nb_rows);
	if (!map->pos2d)
	{
		free(map->colors);
		free(map->heights);
		perror("Error alloc");
		exit(1);
	}
}

void	allocate_map_lines(t_map *map, char **str_line_elems, char *line,
		int row_elems)
{
	map->heights[row_elems] = malloc(strtab_len_valid_elems(str_line_elems)
			* sizeof(int));
	if (!map->heights[row_elems])
		exit_alloc_error(line, str_line_elems, map, row_elems);
	map->colors[row_elems] = malloc(strtab_len_valid_elems(str_line_elems)
			* sizeof(t_color));
	if (!map->colors[row_elems])
	{
		free(map->heights[row_elems]);
		exit_alloc_error(line, str_line_elems, map, row_elems);
	}
	map->pos2d[row_elems] = malloc(strtab_len_valid_elems(str_line_elems)
			* sizeof(t_pos));
	if (!map->pos2d[row_elems])
	{
		free(map->colors[row_elems]);
		free(map->heights[row_elems]);
		exit_alloc_error(line, str_line_elems, map, row_elems);
	}
}

void	set_heights_colors(t_map *map, char **str_line_elems, int row_elems)
{
	char	**str_elem;
	int		i_str_line_elems;
	int		col_heights;

	i_str_line_elems = -1;
	col_heights = -1;
	while (str_line_elems[++i_str_line_elems])
	{
		str_elem = ft_split(str_line_elems[i_str_line_elems], ",");
		if (strtab_len(str_elem) == 2)
		{
			map->heights[row_elems][++col_heights] = ft_atoi(str_elem[0]);
			map->colors[row_elems][col_heights]
				= int_to_rgb(ft_atoui_base(ft_str_toupper(str_elem[1])
						+ 2, "0123456789ABCDEF"));
		}
		else
		{
			map->heights[row_elems][++col_heights]
				= ft_atoi(str_line_elems[i_str_line_elems]);
			map->colors[row_elems][col_heights] = int_to_rgb(0xFFFFFF);
		}
		free_tab_str(str_elem);
	}
}

void	process_init_line(t_map *map, char *line, int row_elems)
{
	char	**str_line_elems;

	str_line_elems = ft_split(line, " \n");
	allocate_map_lines(map, str_line_elems, line, row_elems);
	set_heights_colors(map, str_line_elems, row_elems);
	free(line);
	free_tab_str(str_line_elems);
}

void	init_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		row_elems;

	allocate_map_vars(map);
	fd = open_map_file(filename);
	line = get_next_line(fd);
	row_elems = 0;
	while (line)
	{
		process_init_line(map, line, row_elems);
		line = get_next_line(fd);
		row_elems++;
	}
	close(fd);
}
