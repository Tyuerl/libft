/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:21:23 by glavette          #+#    #+#             */
/*   Updated: 2021/10/25 23:14:17 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = ft_strlen(dst);
	dst_len = i;
	j = 0;
	if (i < dstsize - 1 && dstsize > 0)
	{
		while (src[j] && i < dstsize - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = 0;
	}	
	if (dst_len >= dstsize)
		dst_len = dstsize;
	return (dst_len + ft_strlen(src));
}
