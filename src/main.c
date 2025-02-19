/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:18:40 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/19 17:14:11 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_map_terminal(t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map.nb_rows)
	{
		col = 0;
		while (col < map.row_len[row])
		{
			__builtin_printf("%d ", map.heights[row][col]);
			col++;
		}
		__builtin_printf("\n");
		row++;
	}
}

int	main(int ac, char **av)
{
	t_param	param;
	t_map	map;

	if (ac != 2)
	{
		if (ac == 1)
			print_msg(ERROR_NO_MAP);
		else
			print_msg(ERROR_TOO_MANY_ARGS);
		exit(EXIT_FAILURE);
	}
	check_map(av[1], &map);
	init_map(&map, av[1]);
	my_init_mlx(&param);
	param.map = map;
	display_plan(&param);
	mlx_put_image_to_window(param.vars.mlx, param.vars.win, param.img.img, 0,
		0);
	mlx_key_hook(param.vars.win, key_hook_func, &param);
	mlx_hook(param.vars.win, 17, 0, exit_cross, &param);
	mlx_loop(param.vars.mlx);
}
