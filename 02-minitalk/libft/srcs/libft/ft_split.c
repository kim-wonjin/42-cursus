/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:02:07 by wokim             #+#    #+#             */
/*   Updated: 2022/02/07 01:10:34 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**free_result(char **result, int i)
{
	while (i--)
	{
		free(result[i]);
		result[i] = 0;
	}
	free(result);
	result = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			p = (char *)s;
			while (*s != c && *s)
				s++;
			result[i] = (char *)malloc(s - p + 1);
			if (!result[i])
				return (free_result(result, i - 1));
			ft_strlcpy(result[i++], p, s - p + 1);
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}
