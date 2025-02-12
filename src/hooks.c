/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:11:27 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/10 16:25:01 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_hook_func(int keycode, t_all *all)
{
	// __builtin_printf("key :%d\n", keycode);
	if (keycode == 65307)
	{
		// mlx_destroy_window(all->img, all->addr);
		end_process(all, FREE_ALL, SUCCESS_ESC);
	}
	return (0);
}

int	mouse_hook_func(int button, int x, int y, void *param)
{
	t_all *all = (t_all *)param; // Cast en t_all
	__builtin_printf("btn:%d x:%d y:%d\n", button, x, y);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	return (0);
}
