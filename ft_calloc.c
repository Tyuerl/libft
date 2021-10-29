/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 03:25:45 by glavette          #+#    #+#             */
/*   Updated: 2021/10/27 00:16:30 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_info;

	new_info = (void *)malloc(count * size);
	if (!new_info)
		return (0);
	ft_bzero(new_info, count * size);
	return (new_info);
}
