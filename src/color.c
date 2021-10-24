/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:45:50 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 11:13:03 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	get_coef_help(int start, int end, int current)
{
	double	distance;
	double	placement;

	distance = end - start;
	placement = current - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

float	get_coef(t_fdf *db, float current_x, float current_y)
{
	float	coef;

	coef = 0;
	if (db->xstep > db->ystep)
		coef = get_coef_help(db->start_x, db->end_x, current_x);
	else
		coef = get_coef_help(db->start_y, db->end_y, current_y);
	return (coef);
}

void	find_color(t_fdf *db)
{
	if (db->color_matrix[(int)db->y][(int)db->x] != -7 &&
		db->color_matrix[(int)db->y1][(int)db->x1] != -7)
	{
		db->col_s = db->color_matrix[(int)db->y][(int)db->x];
		db->col_e = db->color_matrix[(int)db->y1][(int)db->x1];
	}
	else if (db->color_matrix[(int)db->y][(int)db->x] != -7 &&
		db->color_matrix[(int)db->y1][(int)db->x1] == -7)
	{
		db->col_s = db->color_matrix[(int)db->y][(int)db->x];
		db->col_e = 0xffffff;
	}
	else if (db->color_matrix[(int)db->y][(int)db->x] == -7 &&
		db->color_matrix[(int)db->y1][(int)db->x1] != -7)
	{
		db->col_s = 0xffffff;
		db->col_e = db->color_matrix[(int)db->y1][(int)db->x1];
	}
	else
	{
		db->col_s = 0xffffff;
		db->col_e = 0xffffff;
	}
}

int	new_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_new_color(t_fdf *db, float current_x, float current_y)
{
	int		itog_color;
	float	coef;
	int		red;
	int		green;
	int		blue;

	coef = get_coef(db, current_x, current_y);
	find_color(db);
	red = new_light((db->col_s >> 16) & 0xFF, (db->col_e >> 16) & 0xFF, coef);
	green = new_light((db->col_s >> 8) & 0xFF, (db->col_e >> 8) & 0xFF, coef);
	blue = new_light(db->col_s & 0xFF, db->col_e & 0xFF, coef);
	itog_color = ((red << 16) | (green << 8) | blue);
	return (itog_color);
}
