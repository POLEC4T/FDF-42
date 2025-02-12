/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:13:57 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/12 13:30:07 by mniemaz          ###   ########.fr       */
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

void	free_mlx(t_all *all)
{
	mlx_destroy_image(all->vars.mlx, all->img.img);
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	mlx_destroy_display(all->vars.mlx);
	free(all->vars.mlx);
}

void	free_map_content(t_all *all)
{
	// free(all->map.row_lengths);
	free_heights(&all->map, all->map.nb_rows);
}

void free_pos2d(t_map *map, int limit)
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