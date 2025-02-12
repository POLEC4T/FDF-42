/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:13 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/12 13:47:31 by mniemaz          ###   ########.fr       */
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
	map->pos2d = malloc(sizeof(t_pos *) * map->nb_rows);
	if (!map->pos2d)
	{
		free(map->heights);
		perror("Error alloc");
		exit(1);
	}
}

void	exit_malloc_error(char *line, char **str_heights, t_map *map,
		int row_heights)
{
	free(line);
	free_tab_str(str_heights);
	free_heights(map, row_heights);
	free_pos2d(map, row_heights);
	perror("Error alloc");
	exit(1);
}

void	process_init_line(t_map *map, char *line, int row_heights)
{
	char	**str_heights;
	int		i_str_heights;
	int		col_heights;

	str_heights = ft_split(line, " \n");
	map->heights[row_heights] = malloc(strtab_len_valid_nbs(str_heights)
			* sizeof(int));
	if (!map->heights[row_heights])
		exit_malloc_error(line, str_heights, map, row_heights);
	map->pos2d[row_heights] = malloc(strtab_len_valid_nbs(str_heights)
			* sizeof(t_pos));
	if (!map->pos2d[row_heights])
	{
		free(map->heights[row_heights]);
		exit_malloc_error(line, str_heights, map, row_heights);
	}
	i_str_heights = -1;
	col_heights = -1;
	while (str_heights[++i_str_heights])
		map->heights[row_heights][++col_heights]
			= ft_atoi(str_heights[i_str_heights]);
	free(line);
	free_tab_str(str_heights);
}

void	init_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		row_heights;

	allocate_map_vars(map);
	fd = open_map_file(filename);
	line = get_next_line(fd);
	row_heights = 0;
	while (line)
	{
		process_init_line(map, line, row_heights);
		line = get_next_line(fd);
		row_heights++;
	}
	close(fd);
}
