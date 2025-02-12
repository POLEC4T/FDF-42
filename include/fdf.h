/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:17:59 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/12 13:30:30 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080
# define CENTER_X WIN_SIZE_X / 2
# define CENTER_Y WIN_SIZE_Y / 2

enum		free_mode
{
	FREE_ALL,
	FREE_HEIGHTS,
	FREE_MLX,
	FREE_POS2D,
	FREE_HEIGHTS_MLX,
	NO_FREE
};

enum		msg_ids
{
	SUCCESS_ESC,
	ERROR_INV_MAP,
	ERROR_INV_MAP_ROW_LEN,
	ERROR_NO_FILE,
	ERROR_MALLOC_BROKE,
	ERROR_NO_MAP,
	ERROR_TOO_MANY_ARGS,
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_line
{
	t_pos	pos1;
	t_pos	pos2;
}			t_line;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_map
{
	t_pos	origin;
	int		step;
	int		height_multiplier;
	int		**heights;
	t_pos	**pos2d;
	int		nb_rows;
	int		nb_cols;
}			t_map;

typedef struct s_all
{
	t_vars	vars;
	t_data	img;
	t_map	map;
}			t_all;

int			key_hook_func(int keycode, t_all *img);
int			mouse_hook_func(int button, int x, int y, void *param);
void		check_map(char *filename, t_map *map);
void		free_tab_str(char **tab);
void		free_heights(t_map *map, int limit);
void		end_process(t_all *all, enum free_mode free_mode,
				enum msg_ids msg_id);
int			strtab_len(char **strlst);
int			strtab_len_valid_nbs(char **strtab);
int			is_number_valid(char *str);
void		print_msg(enum msg_ids id);
void		exit_acc_to_msg_id(enum msg_ids id);
void		free_mlx(t_all *all);
void		free_map_content(t_all *all);
void		free_pos2d(t_map *map, int limit);
void		init_map(t_map *map, char *filename);
int			open_map_file(char *filename);

#endif