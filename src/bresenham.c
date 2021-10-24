/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:46:00 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 12:02:09 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_fdf *databox, int x, int y, int color)
{
	char	*dst;

	dst = databox->addr + (y * databox->l_l + x * (databox->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(t_fdf *databox)
{
	databox->y = 0;
	while (databox->y < databox->height)
	{
		databox->x = 0;
		while (databox->x < databox-> width)
		{
			if (databox->x < databox->width - 1)
			{
				databox->x1 = databox->x + 1;
				databox->y1 = databox->y;
				bresenham(databox);
			}
			if (databox->y < databox->height - 1)
			{
				databox->x1 = databox->x;
				databox->y1 = databox->y + 1;
				bresenham(databox);
			}
			databox->x++;
		}
		databox->y++;
	}
}

void	izo(t_fdf *db)
{
	float	previous_x;
	float	previous_y;
	float	previous_x1;
	float	previous_y1;

	previous_x = db->br_x;
	previous_y = db->br_y;
	previous_x1 = db->br_x1;
	previous_y1 = db->br_y1;
	db->br_x = previous_x * cos(M_PI / 6) + \
	previous_y * cos(5 * M_PI / 6) - db->z * cos(M_PI / 2);
	db->br_y = previous_x * sin(M_PI / 6) + \
	previous_y * sin(5 * M_PI / 6) - db->z * sin(M_PI / 2);
	db->br_x1 = previous_x1 * cos(M_PI / 6) + \
	previous_y1 * cos(5 * M_PI / 6) - db->z1 * cos(M_PI / 2);
	db->br_y1 = previous_x1 * sin(M_PI / 6) + \
	previous_y1 * sin(5 * M_PI / 6) - db->z1 * sin(M_PI / 2);
}

void	bresenham(t_fdf *db)
{
	bres_init(db);
	zoom(db);
	izo(db);
	shift(db);
	bres_find_step(db);
	bres_step_stcol(db);
	while ((int)(db->br_x - db->br_x1) || (int)(db->br_y - db->br_y1))
	{
		db->color = get_new_color(db, db->br_x, db->br_y);
		if (db->br_x >= 0 && db->br_y >= 0
			&& db->br_x < SIZE_X && db->br_y < SIZE_Y)
		{
			my_mlx_pixel_put(db, db->br_x, db->br_y, db->color);
		}
		db->br_x += db->xstep;
		db->br_y += db->ystep;
	}
}
