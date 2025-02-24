/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:05 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/24 12:54:12 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_msg(enum e_msg_ids id)
{
	if (id == SUCCESS_EXIT_ESC)
		write(1, "Successfully exited with ESC.\n", 30);
	if (id == SUCCESS_EXIT_CROSS)
		write(1, "Successfully exited with top right cross.\n", 42);
	if (id == ERROR_INV_MAP)
		write(2, "Error: The provided map is invalid.\n", 37);
	if (id == ERROR_NO_MAP)
		write(2, "Error: Please provide a map file.\n", 34);
	if (id == ERROR_TOO_MANY_ARGS)
		write(2, "Error: Too many arguments provided.\n", 37);
}

int	get_max_row_len(t_map *map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < map->nb_rows)
	{
		if (map->row_len[i] > max)
			max = map->row_len[i];
		i++;
	}
	return (max);
}

int ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}