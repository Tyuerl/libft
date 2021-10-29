/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:21:50 by glavette          #+#    #+#             */
/*   Updated: 2021/10/26 23:17:25 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *s, int sygn)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(s[i]) && s[i])
	{
		i++;
	}
	if (ft_strncmp(s, "9223372036854775807", 20) > 0 && i >= 19)
	{
		if (sygn == 1)
			return (-1);
		else
			return (0);
	}
	return (155);
}

int	ft_atoi(const char *s)
{
	size_t		i;
	long long	res;
	int			sygn;

	sygn = 1;
	res = 0;
	i = 0;
	while (((s[i] >= 9 && s[i] <= 13) || (s[i] == ' ')) && (s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
		if (s[i - 1] == '-')
			sygn = -sygn;
	}
	if (ft_check(s + i, sygn) == -1 || ft_check(s + i, sygn) == 0)
		return (ft_check((s + i), sygn));
	while (ft_isdigit(s[i]) && s[i])
	{
		res = res * 10 + (long long)(s[i] - '0');
		i++;
	}
	res = (long long)sygn * res;
	return ((int)res);
}
