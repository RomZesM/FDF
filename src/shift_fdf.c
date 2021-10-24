/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:29:49 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 11:57:00 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	shift_count(t_fdf *db)
{
	int		i;
	int		j;

	i = db->z_matrix[(int)db->s_y][(int)db->s_x];
	j = db->z_matrix[(int)db->s_y1][(int)db->s_x1];
	db->s_x = (db->s_x - db->s_y) * cos(db->angle);
	db->s_y = (db->s_x + db->s_y) * sin(db->angle) - i;
	db->s_x1 = (db->s_x1 - db->s_y1) * cos(db->angle);
	db->s_y1 = (db->s_x1 + db->s_y1) * sin(db->angle) - j;
	if (db->s_x < 0 && modul(db->s_x) > db->start_x_shift)
		db->start_x_shift = ceil(modul(db->s_x));
	if (db->s_x1 < 0 && modul(db->s_x1) > db->start_x_shift)
		db->start_x_shift = ceil(modul(db->s_x));
	if (db->s_y < 0 && modul(db->s_y) > db->start_y_shift)
		db->start_y_shift = ceil(modul(db->s_y));
	if (db->s_y1 < 0 && modul(db->s_y1) > db->start_y_shift)
		db->start_y_shift = ceil(modul(db->s_y1));
}

void	ft_find_shif_help_1(int i, int j, t_fdf *db)
{
	db->s_x1 = j + 1;
	db->s_y1 = i;
	db->s_x = j;
	db->s_y = i;
}

void	ft_find_shif_help_2(int i, int j, t_fdf *db)
{
	db->s_x1 = j;
	db->s_y1 = i + 1;
	db->s_x = j;
	db->s_y = i;
}

void	find_shift(t_fdf *db)
{
	float	i;
	float	j;

	i = 0;
	while (i < db->height)
	{
		j = 0;
		while (j < db-> width)
		{
			if (j < db->width - 1)
			{
				ft_find_shif_help_1(i, j, db);
				shift_count(db);
			}
			if (i < db->height - 1)
			{
				ft_find_shif_help_2(i, j, db);
				shift_count(db);
			}
			j++;
		}
		i++;
	}
	db->start_x_shift = db->start_x_shift * db->zoom + 100;
	db->start_y_shift = db->start_y_shift * db->zoom + 10;
}
