/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:46:12 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:46:13 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_all_match(char *str, char *to_find, int to_find_len)
{
	int index;

	index = 0;
	while (index < to_find_len)
	{
		if (str[index] == to_find[index])
		{
			index++;
			if (index == to_find_len)
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	to_find_len;
	size_t	index;
	size_t	j;

	to_find_len = 0;
	index = 0;
	while (to_find[to_find_len] != '\0')
		to_find_len++;
	if (to_find_len == 0)
		return ((char*)str);
	if (len == 0)
		return (0);
	while (str[index] != '\0' && index <= len - to_find_len)
	{
		if (str[index] == to_find[0])
		{
			j = ft_all_match((char*)&str[index], (char*)to_find, to_find_len);
			if (j == 1)
				return ((char*)&str[index]);
		}
		index++;
	}
	return (0);
}
