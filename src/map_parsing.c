/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:01:43 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 19:06:02 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"

int	iterate_number_part(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int	iterate_hex_part(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '0' && str[i + 1] && str[i + 1] == 'x')
	{
		i += 2;
		while (str[i] && ft_isdigit_base(str[i], 16))
			i++;
	}
	return (i);
}

int	is_element_valid(char *str)
{
	int	i_nb;
	int	i_hex;
	int	len_nb_hex;

	i_hex = 0;
	i_nb = iterate_number_part(str);
	if (str[i_nb] == ',')
		i_hex++;
	i_hex += iterate_hex_part(str + i_nb + i_hex);
	len_nb_hex = i_hex - 3;
	return ((int)ft_strlen(str) == i_nb + i_hex && len_nb_hex <= MAX_HEX_LEN
		&& (!(len_nb_hex <= 0 && i_hex > 0)));
}

/**
 * @brief
 * - Checks if the line is valid:
 * 	- inv if the line has a different number of columns than the previous one
 * 	- inv if the line has an invalid element (see function is_element_valid)
 * - increments the number of rows
 */
void	process_check_line(char *line, t_map *map)
{
	char	**str_heights;
	int		nb_cols_prev_line;

	str_heights = ft_split(line, " \n");
	if (strtab_len_valid_elems(str_heights) != strtab_len(str_heights))
		exit_invalid_map(line, str_heights);
	nb_cols_prev_line = map->nb_cols;
	map->nb_cols = strtab_len(str_heights);
	if (map->nb_cols != nb_cols_prev_line && map->nb_rows > 0)
		exit_invalid_map(line, str_heights);
	map->nb_rows++;
	free_tab_str(str_heights);
}

/**
 * @brief
 * - Check the map file, the file is invalid if:
 * 	- a line has a different number of columns than the previous one
 * 	- a line has an invalid element (see function is_element_valid)
 * - Set the sizes of the map (nb_rows, nb_cols)
 */
void	check_map(char *filename, t_map *map)
{
	char	*line;
	int		fd;

	map->nb_rows = 0;
	map->nb_cols = 0;
	fd = open_map_file(filename);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	while (line)
	{
		process_check_line(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
