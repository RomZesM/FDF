/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:45:34 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 12:28:34 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	clear_window(t_fdf *list)
{
	mlx_destroy_image(list->mlx_ptr, list->img_ptr);
	list->img_ptr = mlx_new_image(list->mlx_ptr, SIZE_X, SIZE_Y);
	list->addr = mlx_get_data_addr(list->img_ptr, \
		&list->bpp, &list->l_l, &list->en);
}

void	ft_esc_exit(t_fdf *databox)
{
	mlx_destroy_image(databox->mlx_ptr, databox->img_ptr);
	ft_clean_2_mass(databox->z_matrix, databox);
	ft_clean_2_mass(databox->color_matrix, databox);
	exit(0);
}

int	key_pressed(int keycode, t_fdf *databox)
{
	if (keycode == 53)
		ft_esc_exit(databox);
	if (keycode == 124)
		databox->x_shift += 20;
	if (keycode == 123)
		databox->x_shift -= 20;
	if (keycode == 126)
		databox->y_shift -= 20;
	if (keycode == 125)
		databox->y_shift += 20;
	if (keycode == 6)
		databox->zoom += 1;
	if (keycode == 7)
		databox->zoom -= 1;
	if (keycode == 0)
		databox->angle += 0.1;
	if (keycode == 1)
		databox->angle -= 0.1;
	clear_window(databox);
	draw_map(databox);
	mlx_put_image_to_window(databox->mlx_ptr, \
		databox->win_ptr, databox->img_ptr, 0, 0);
	return (0);
}

void	ft_check_file(char *filename)
{
	int		fd;
	int		r;
	char	buffer[7];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File is incorrect.\n");
		exit(1);
	}
	r = read(fd, buffer, 7);
	if (r == -1)
	{
		ft_printf("File is incorrect.\n");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_fdf	img_box;
	t_fdf	*b_pt;

	if (argc != 2)
		return (0);
	ft_check_file(argv[1]);
	b_pt = &img_box;
	mlx_start(b_pt);
	read_map(argv[1], b_pt);
	find_top(b_pt);
	find_depth(b_pt);
	zoom_count(b_pt);
	start_param_set(b_pt);
	find_shift(b_pt);
	draw_map(b_pt);
	mlx_put_image_to_window (b_pt->mlx_ptr, b_pt->win_ptr, b_pt->img_ptr, 0, 0);
	mlx_key_hook(b_pt->win_ptr, key_pressed, b_pt);
	mlx_loop(b_pt->mlx_ptr);
	return (0);
}
