/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:26:16 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/21 10:31:15 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	end_process(t_param *param, enum e_msg_ids msg_id)
{
	free_mlx(param);
	free_colors(&param->map, param->map.nb_rows);
	free_heights(&param->map, param->map.nb_rows);
	free_pos2d(&param->map, param->map.nb_rows);
	free(param->map.row_len);
	print_msg(msg_id);
	exit_acc_to_msg_id(msg_id);
}

int	exit_cross(t_param *param)
{
	end_process(param, SUCCESS_EXIT_CROSS);
	return (0);
}

int	key_hook_func(int keycode, t_param *param)
{
	if (keycode == 65307)
		end_process(param, SUCCESS_EXIT_ESC);
	return (0);
}

void	exit_invalid_map(char *line, char **str_heights, int fd)
{
	if (line)
		free(line);
	if (str_heights)
		free_tab_str(str_heights);
	if (fd != -1)
		close(fd);
	print_msg(ERROR_INV_MAP);
	exit(EXIT_FAILURE);
}

/**
 * @brief Exit the program with the appropriate 
 * mode (success or error) according to the message id
 */
void	exit_acc_to_msg_id(enum e_msg_ids id)
{
	if (id == ERROR_INV_MAP || id == ERROR_NO_FILE || id == ERROR_MALLOC_BROKE
		|| id == ERROR_NO_MAP || id == ERROR_TOO_MANY_ARGS)
		exit(EXIT_FAILURE);
	else if (id == SUCCESS_EXIT_ESC || SUCCESS_EXIT_CROSS)
		exit(EXIT_SUCCESS);
}
