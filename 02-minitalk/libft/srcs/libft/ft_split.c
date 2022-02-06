/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:02:07 by wokim             #+#    #+#             */
/*   Updated: 2021/05/19 20:02:26 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t count;

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

static char		**free_result(char **result, int i)
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

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			p = (char *)s;
			while (*s != c && *s)
				s++;
			if (!(result[i] = (char *)malloc(s - p + 1)))
				return (free_result(result, i - 1));
			ft_strlcpy(result[i++], p, s - p + 1);
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}
