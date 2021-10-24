/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:29:46 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 11:13:16 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_copy_color(char **line, int *c_line, t_fdf *db)
{
	int		i;
	char	*color_buf;

	i = 0;
	while (i < db->width)
	{
		color_buf = ft_strrchr(line[i], ',');
		if ((color_buf != NULL))
		{
			c_line[i] = ft_atoi_base_m(ft_substr_m(color_buf + 3, 0, 6), 16);
		}
		else
			c_line[i] = -7;
		i++;
	}
	return (0);
}

int	ft_copy_map_str( char *numbers, int *z_line, int *c_line, t_fdf *db)
{
	int		i;
	char	**line;

	line = NULL;
	line = ft_split(numbers, ' ');
	ft_copy_color(line, c_line, db);
	i = 0;
	while (i < db->width)
	{
		while (i < db->width)
		{
			z_line[i] = ft_atoi(line[i]);
			free(line[i]);
			i++;
		}
	}
	free(line);
	return (0);
}

int	ft_get_mem(t_fdf *db)
{
	int		i;

	db->z_matrix = (int **)malloc(sizeof(int *) * db->height * 10 + 1);
	db->color_matrix = (int **)malloc(sizeof(int *) * db->height * 10 + 1);
	if (db->z_matrix == NULL || db->color_matrix == NULL)
		return (0);
	i = 0;
	while (i < db->height)
	{
		db->z_matrix[i] = (int *)malloc(sizeof(int) * db->width + 1);
		db->color_matrix[i] = (int *)malloc(sizeof(int) * db->width + 1);
		if (db->z_matrix[i] == NULL || db->color_matrix[i] == NULL)
			return (0);
		i++;
	}
	return (0);
}

int	read_map(char *filename, t_fdf *db)
{
	int		i;
	int		fd;
	char	*mapline;

	mapline = NULL;
	ft_get_height(filename, db);
	ft_get_width(filename, db);
	ft_get_mem(db);
	fd = open(filename, O_RDONLY, 0);
	if (fd == -1)
		return (0);
	i = 0;
	while (i < db->height)
	{
		mapline = get_next_line(fd);
		ft_copy_map_str(mapline, db->z_matrix[i], \
		db->color_matrix[i], db);
		free(mapline);
		i++;
	}
	close(fd);
	return (0);
}
