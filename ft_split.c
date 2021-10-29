/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:37:53 by glavette          #+#    #+#             */
/*   Updated: 2021/10/29 19:19:23 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	j;

	i = 0;
	j = i;
	count = j;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		else
		{
			if (j != 0)
				count++;
			j = 0;
		}
		i++;
	}
	if (j != 0)
		count++;
	return (count);
}

static int	ft_ltr_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_kostil(size_t *a, size_t *c)
{
	*a = 0;
	*c = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	i[2];
	char	**ar;

	if (!s)
		return (0);
	ar = (char **) malloc(sizeof(char *) * (ft_word_len(s, c) + 1));
	if (!ar)
		return (0);
	ft_kostil(&i[0], &i[1]);
	while (s[i[0]])
	{
		if (s[i[0]] != c)
		{
			ar[i[1]] = malloc(sizeof(char) * (ft_ltr_len(s + i[0], c) + 1));
			if (!ar[i[1]])
				return (0);
			ft_strlcpy(ar[i[1]], s + i[0], ft_ltr_len(s + i[0], c) + 1);
			i[0] += ft_ltr_len(s + i[0], c);
			i[1]++;
		}
		else
			i[0]++;
	}
	ar[i[1]] = 0;
	return (ar);
}
