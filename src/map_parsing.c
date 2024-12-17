/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:01:43 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/17 22:09:22 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	contains_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	strlst_len(char **strlst)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (strlst[i])
	{
		if (contains_digit(strlst[i]))
			count++;
		i++;
	}
	return (count);
}

void free_tab_str(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
    {
        free(tab[i]);
    }
    free(tab);
}

void	set_map_sizes(char *filename, t_map *map)
{
	char	**values;
	char	*line;
	int		max_nb_vals;
	int		count_max;
	int		fd;

	map->nb_rows = 0;
	max_nb_vals = INT_MIN;
	count_max = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		values = ft_split(line, ' ');
		map->len_biggest_row = strlst_len(values);
		if (map->len_biggest_row > max_nb_vals)
		{
			if (count_max)
				write(1, "Warning, lines are not the same size", 1);
			max_nb_vals = map->len_biggest_row;
		}
		map->nb_rows++;
		free(line);
		line = get_next_line(fd);
		free_tab_str(values);
	}
	map->len_biggest_row = max_nb_vals;
}
