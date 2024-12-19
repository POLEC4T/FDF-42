/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:01:43 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/19 22:33:33 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"

int	is_number_valid(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	// else if (str[i] && str[i + 1] && str[i] == '0' && str[i + 1] == 'x')
	// 	i = 2;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (ft_strlen(str) == i);
}

void	check_map(char *filename, t_map *map)
{
	char	**str_values;
	char	*line;
	int		max_nb_vals;
	int		count_max;
	int		fd;

	map->nb_rows = 0;
	max_nb_vals = INT_MIN;
	count_max = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_msg(ERROR_NO_FILE);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		str_values = ft_split(line, " \n");
		if (strtab_len_valid_nbs(str_values) != strtab_len(str_values))
		{
			free(line);
			free_tab_str(str_values);
			print_msg(ERROR_INV_MAP);
			exit(1);
		}
		map->len_biggest_row = strtab_len(str_values);
		if (map->len_biggest_row > max_nb_vals)
		{
			if (count_max > 1)
				write(1, "Warning, lines are not the same size", 1);
			max_nb_vals = map->len_biggest_row;
			count_max++;
		}
		map->nb_rows++;
		free(line);
		line = get_next_line(fd);
		free_tab_str(str_values);
	}
	map->len_biggest_row = max_nb_vals;
}
