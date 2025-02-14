/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:18:40 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 18:55:12 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_all	all;
	t_map	map;

	if (ac != 2)
	{
		if (ac == 1)
			print_msg(ERROR_NO_MAP);
		else
			print_msg(ERROR_TOO_MANY_ARGS);
		exit(1);
	}
	check_map(av[1], &map);
	init_map(&map, av[1]);
	my_init_mlx(&all);
	all.map = map;
	display_plan(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	mlx_key_hook(all.vars.win, key_hook_func, &all);
	mlx_hook(all.vars.win, 17, 0, exit_cross, &all);
	mlx_loop(all.vars.mlx);
}
