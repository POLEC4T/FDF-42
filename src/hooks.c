/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:11:27 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 19:00:48 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_hook_func(int keycode, t_all *all)
{
	if (keycode == 65307)
		end_process(all, SUCCESS_EXIT_ESC);
	return (0);
}
