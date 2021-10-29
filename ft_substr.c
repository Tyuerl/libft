/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 04:14:27 by glavette          #+#    #+#             */
/*   Updated: 2021/10/27 00:15:34 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*substr;

	if (!s)
		return (0);
	j = ft_strlen(s + start);
	if (len > j)
		len = j;
	substr = (char *)malloc((len + 1));
	if (!substr)
		return (0);
	j = 0;
	if (start > ft_strlen(s))
	{
		substr[j] = 0;
		return (substr);
	}
	while (s[start] && j < len)
	{
		substr[j] = s[start];
		j++;
		start++;
	}
	substr[j] = 0;
	return (substr);
}
