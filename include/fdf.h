/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:17:59 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/15 19:09:06 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080
# define CENTER_X WIN_SIZE_X / 2
# define CENTER_Y WIN_SIZE_Y / 2

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_all
{
	t_vars		vars;
	t_data		img;
}				t_all;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

int				key_hook_func(int keycode, t_data *img);
int				mouse_hook_func(int button, int x, int y, void *param);
void			print_square(t_data *img, int x, int y, int size, int color);

#endif