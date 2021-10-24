/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:45:45 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 11:13:23 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	minimum(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	modul(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	start_param_set(t_fdf *db)
{
	db->angle = 0.523599;
	db->x_shift = 0;
	db->y_shift = 0;
	db->start_y_shift = 0;
	db->start_x_shift = 0;
}

void	mlx_start(t_fdf *db)
{
	db->mlx_ptr = mlx_init();
	db->win_ptr = mlx_new_window(db->mlx_ptr, SIZE_X, SIZE_Y, "fdf");
	db->img_ptr = mlx_new_image(db->mlx_ptr, SIZE_X, SIZE_Y);
	db->addr = mlx_get_data_addr(db->img_ptr, &db->bpp, \
				&db->l_l, &db->en);
}
