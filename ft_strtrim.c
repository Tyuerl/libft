/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 04:33:06 by glavette          #+#    #+#             */
/*   Updated: 2021/10/27 02:26:42 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	size_t	i;
	char	*s;

	if (!s1)
		return (0);
	end = ft_strlen(s1);
	start = 0;
	i = start;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	s = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s)
		return (0);
	while (start < end)
		s[i++] = s1[start++];
	s[i] = 0;
	return (s);
}
