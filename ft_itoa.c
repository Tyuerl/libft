/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 03:49:11 by glavette          #+#    #+#             */
/*   Updated: 2021/10/29 18:52:03 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_num(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -(n / 10);
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_alloc(int n)
{
	char	*str;

	if (n == 0)
	{
		str = (char *) malloc(sizeof(char) * 2);
		if (!str)
			return (0);
		str[1] = 0;
		str[0] = '0';
	}
	else if (n < 0)
	{
		str = (char *) malloc(sizeof(char) * (ft_len_num(n) + 2));
		if (!str)
			return (0);
		str[ft_len_num(n) + 1] = 0;
	}
	else
	{
		str = (char *) malloc(sizeof(char) * (ft_len_num(n) + 1));
		if (!str)
			return (0);
		str[ft_len_num(n)] = 0;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_len_num(n);
	str = ft_alloc(n);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		str[i] = -(n % 10) + '0';
		n = - (n / 10);
	}
	i--;
	while (n)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}
