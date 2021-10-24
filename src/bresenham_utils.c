/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:28:59 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 12:21:53 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	shift(t_fdf *db)
{
	db->br_x += db->x_shift;
	db->br_x1 += db->x_shift;
	db->br_y += db->y_shift;
	db->br_y1 += db->y_shift;
}

void	bres_init(t_fdf *db)
{
	db->br_x = db->x;
	db->br_x1 = db->x1;
	db->br_y = db->y;
	db->br_y1 = db->y1;
	db->z = db->z_matrix[(int)db->br_y][(int)db->br_x] * db->zoom;
	db->z1 = db->z_matrix[(int)db->br_y1][(int)db->br_x1] * db->zoom;
}

void	bres_find_step(t_fdf *db)
{
	int		max;

	max = 0;
	db->xstep = db->br_x1 - db->br_x;
	db->ystep = db->br_y1 - db->br_y;
	max = maximum(modul(db->xstep), modul(db->ystep));
	db->xstep /= max;
	db->ystep /= max;
}

void	bres_step_stcol(t_fdf *db)
{
	db->br_x += db->start_x_shift;
	db->br_x1 += db->start_x_shift;
	db->br_y += db->start_y_shift;
	db->br_y1 += db->start_y_shift;
	db->start_x = db->br_x;
	db->end_x = db->br_x1;
	db->start_y = db->br_y;
	db->end_y = db->br_y1;
}

void	zoom(t_fdf *db)
{
	db->br_x *= db->zoom;
	db->br_y *= db->zoom;
	db->br_x1 *= db->zoom;
	db->br_y1 *= db->zoom;
}
