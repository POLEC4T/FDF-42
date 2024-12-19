/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:13:57 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/19 23:24:45 by mniemaz          ###   ########.fr       */
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

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nb_rows)
	{
		free(map->values[i]);
		i++;
	}
	free(map->values);
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
	free(all->map.row_lengths);
	free_map(&all->map);
}