/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:13:57 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/19 19:11:40 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_tab_str(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_heights(t_map *map, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		free(map->heights[i]);
		i++;
	}
	free(map->heights);
}

void	free_colors(t_map *map, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		free(map->colors[i]);
		i++;
	}
	free(map->colors);
}

void	free_mlx(t_param *param)
{
	mlx_destroy_image(param->vars.mlx, param->img.img);
	mlx_destroy_window(param->vars.mlx, param->vars.win);
	mlx_destroy_display(param->vars.mlx);
	free(param->vars.mlx);
}

void	free_pos2d(t_map *map, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		free(map->pos2d[i]);
		i++;
	}
	free(map->pos2d);
}
