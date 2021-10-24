/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:29:31 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 11:55:47 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

size_t	ft_funct(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	int		i;

	i = start;
	j = 0;
	while (s[i])
	{
		i++;
		j++;
	}
	if (j < len)
		return (j);
	return (len);
}

char	*ft_substr_m(char const *s, unsigned int start, int len)
{
	char	*p;
	int		i;

	if (s)
		len = ft_funct(s, start, len);
	i = 0;
	p = (char *)malloc(len + 1);
	if (!p || !s)
		return (NULL);
	while (len && start < (unsigned int)ft_strlen(s) && s[start] != '\n')
	{
		p[i] = s[start];
		start++;
		len--;
		i++;
	}
	p[i] = '\0';
	return (p);
}
