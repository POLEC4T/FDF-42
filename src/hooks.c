/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:11:27 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/15 16:12:08 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_hook_func(int keycode, t_data *img)
{
	// __builtin_printf("key :%d\n", keycode);
	if (keycode == 65307)
		mlx_destroy_window(img->img, img->addr);
	return (0);
}

int	mouse_hook_func(int button, int x, int y, void *param)
{
	t_all *all = (t_all *)param; // Cast en t_all
	__builtin_printf("btn:%d x:%d y:%d\n", button, x, y);
	print_square(&all->img, x - 10, y - 10, 20, 0x00FF0000);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	return (0);
}
