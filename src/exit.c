/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:26:16 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 19:08:28 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	end_process(t_all *all, enum e_msg_ids msg_id)
{
	free_mlx(all);
	free_colors(&all->map, all->map.nb_rows);
	free_heights(&all->map, all->map.nb_rows);
	free_pos2d(&all->map, all->map.nb_rows);
	print_msg(msg_id);
	exit_acc_to_msg_id(msg_id);
}

int	exit_cross(t_all *all)
{
	end_process(all, SUCCESS_EXIT_CROSS);
	return (0);
}

void	exit_invalid_map(char *line, char **str_heights)
{
	free(line);
	free_tab_str(str_heights);
	print_msg(ERROR_INV_MAP);
	exit(1);
}

void	exit_acc_to_msg_id(enum e_msg_ids id)
{
	if (id == ERROR_INV_MAP || id == ERROR_NO_FILE || id == ERROR_MALLOC_BROKE
		|| id == ERROR_NO_MAP || id == ERROR_TOO_MANY_ARGS)
		exit(1);
	else if (id == SUCCESS_EXIT_ESC || SUCCESS_EXIT_CROSS)
		exit(0);
}
