/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:00 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 12:01:03 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft/libft.h"

# define SIZE_X 1600
# define SIZE_Y 760

typedef struct s_fdf {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		l_l;
	int		en;
	int		zoom;
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		z;
	int		z1;
	float	br_x;
	float	br_y;
	float	br_x1;
	float	br_y1;
	float	xstep;
	float	ystep;
	float	start_x;
	float	end_x;
	float	start_y;
	float	end_y;
	int		col_s;
	int		col_e;
	int		color;
	float	angle;
	float	rot_angle_x;
	float	rot_angle_y;
	float	rot_angle_z;
	int		x_shift;
	int		y_shift;
	int		start_x_shift;
	int		start_y_shift;
	float	s_y1;
	float	s_x1;
	float	s_y;
	float	s_x;
	int		height;
	int		width;
	int		top;
	int		depth;
	int		**z_matrix;
	int		**color_matrix;
}				t_fdf;

void	bresenham(t_fdf *databox);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		read_map(char *filename, t_fdf *databox);
void	draw_map(t_fdf *databox);
int		maximum(int a, int b);
int		minimum(int a, int b);
float	modul(float i);
int		ft_atoi_base(char *str, int str_base);
void	izometric(t_fdf *databox);
int		get_new_color(t_fdf *databox, float current_x, float current_y);
void	isometric_count(t_fdf *db);
void	find_depth(t_fdf *databox);
void	find_top(t_fdf *databox);
char	*ft_substr_m(char const *s, unsigned int start, int len);
void	ft_clean_2_mass(int **ptr, t_fdf *databox);
int		ft_atoi_base_m(char *str, int str_base);
int		ft_wordcounting(char *s, char c);
void	ft_get_height(char *fn, t_fdf *db);
void	ft_get_width(char *fn, t_fdf *db);
void	ft_esc_exit(t_fdf *databox);
void	ft_find_shif_help_1(int i, int j, t_fdf *db);
void	ft_find_shif_help_2(int i, int j, t_fdf *db);
void	ft_check_file(char *filename);
void	zoom_count(t_fdf *databox);
void	shift_count(t_fdf *db);
void	find_shift(t_fdf *db);
void	start_param_set(t_fdf *db);
void	mlx_start(t_fdf *db);
void	bres_init(t_fdf *db);
void	bres_find_step(t_fdf *db);
void	bres_step_stcol(t_fdf *db);
void	shift(t_fdf *db);
void	zoom(t_fdf *db);

#endif
