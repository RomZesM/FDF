/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:29:41 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 11:13:14 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_wordcounting(char *s, char c)
{
	int	t;
	int	i;

	i = 0;
	t = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i] != '\n') && (s[i + 1] == c
				|| s[i + 1] == '\0' || s[i + 1] == '\n'))
			t++;
		i++;
	}
	return (t);
}

void	ft_clean_2_mass(int **ptr, t_fdf *databox)
{
	int	i;

	i = 0;
	while (i < databox->height)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_get_height(char *fn, t_fdf *db)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(fn, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_printf("NO FILE!\n");
		exit(0);
	}
	line = NULL;
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	db->height = i;
	close(fd);
	free(line);
}

int	ft_check_map(int i, int p)
{
	if (i != p)
	{
		ft_printf("Incorrect map. Wrong line lenght.\n");
		exit(1);
	}
	else
		return (0);
}

void	ft_get_width(char *fn, t_fdf *db)
{
	int		i;
	int		p;
	int		fd;
	char	*line;

	fd = open(fn, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_printf("NO FILE!\n");
		exit(0);
	}
	line = get_next_line(fd);
	p = ft_wordcounting(line, ' ');
	while (line != NULL)
	{
		i = ft_wordcounting(line, ' ');
		ft_check_map(i, p);
		p = i;
		free(line);
		line = get_next_line(fd);
	}
	db->width = i;
	close(fd);
	free(line);
}
