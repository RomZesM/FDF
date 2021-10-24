/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_m.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:29:14 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 11:13:06 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	ft_isdigit_m(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'F')
		|| (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}

static int	ft_new_ret(char *str, int i)
{
	if (str[i] <= '9')
		return (str[i] - '0');
	return (ft_toupper(str[i]) - 55);
}

int	ft_atoi_base_m(char *str, int str_base)
{
	int		i;
	int		neg;
	int		ret;

	neg = 1;
	ret = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit_m(str[i]))
			return (-1);
		ret *= str_base;
		ret += ft_new_ret(str, i);
		i++;
	}
	free(str);
	return (ret * neg);
}
