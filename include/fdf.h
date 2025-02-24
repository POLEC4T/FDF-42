/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:17:59 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/24 11:10:07 by mniemaz          ###   ########.fr       */
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

# define WIN_SIZE_X 3000
# define WIN_SIZE_Y 2000
# define MAX_HEX_LEN 8
# define M_PI 3.14159265358979323846

# define ABS(x) ((x < 0) * -x + (x >= 0) * x)
# define ABS(x) (-x * (x < 0) + x * (x >= 0))
enum			e_msg_ids
{
	SUCCESS_EXIT_ESC,
	SUCCESS_EXIT_CROSS,
	ERROR_INV_MAP,
	ERROR_NO_MAP,
	ERROR_TOO_MANY_ARGS,
};

typedef struct s_data
{
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img;
}				t_data;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_line
{
	t_pos		from;
	t_pos		to;
}				t_line;

typedef struct s_step_colors
{
	double		r;
	double		g;
	double		b;
}				t_step_colors;

typedef struct s_grid_pos
{
	int			row;
	int			col;
}				t_grid_pos;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_map
{
	t_pos		origin;
	int			step;
	int			height_multiplier;
	int			**heights;
	t_color		**colors;
	t_pos		**pos2d;
	int			nb_rows;
	int			*row_len;
}				t_map;

typedef struct s_param
{
	t_vars		vars;
	t_data		img;
	t_map		map;
}				t_param;

int				key_hook_func(int keycode, t_param *img);
void			check_map(char *filename, t_map *map);
void			free_tab_str(char **tab);
void			free_heights(t_map *map, int limit);
void			end_process(t_param *param, enum e_msg_ids msg_id);
int				strtab_len(char **strlst);
int				strtab_len_valid_elems(char **strtab);
int				is_element_valid(char *str);
void			print_msg(enum e_msg_ids id);
void			exit_acc_to_msg_id(enum e_msg_ids id);
void			free_mlx(t_param *param);
void			free_colors(t_map *map, int limit);
void			free_pos2d(t_map *map, int limit);
void			init_map(t_map *map, char *filename);
void			exit_alloc_error(char **lines, char **str_line_elems,
					t_map *map, int row_elems);
int				rgb_to_int(t_color color);
t_color			int_to_rgb(int color);
void			z_rotate(t_pos *pos, double angle, t_param *param);
void			x_rotate(t_pos *pos, int *height, double angle, t_param *param);
t_step_colors	calc_step_colors(t_param *param, t_grid_pos pos1,
					t_grid_pos pos2);
t_color			calc_color(t_param *param, t_grid_pos pos1, int i,
					t_step_colors step_colors);
int				bresenham_line_counter(t_line line);
void			bresenham_line(t_param *param, t_grid_pos cell_from,
					t_grid_pos cell_to);
void			my_mlx_pixel_put(t_data *data, t_pos pos, int color);
void			my_init_mlx(t_param *param);
int				exit_cross(t_param *param);
int				display_plan(t_param *param);
void			exit_invalid_map(char *line, char **str_heights, int fd);
int				get_max_row_len(t_map *map);
void			exit_perror(char *msg);
int				end_with(char *str, char *to_find);
void			allocate_map_vars(t_map *map);
void			allocate_map_lines(t_map *map, char **str_line_elems,
					char **lines, int row_elems);
void			free_map_vars(t_map *map, int limit);
void			exit_out_of_range_error(char **lines, char **str_line_elems,
					t_map *map, int row_elems);

#endif