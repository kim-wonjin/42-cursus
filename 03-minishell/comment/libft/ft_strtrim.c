/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:46:21 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:46:22 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cmp_set(char const c, char const *set)
{
	char	tmp1;
	char	*tmp2;
	int		i;

	tmp1 = (char)c;
	tmp2 = (char*)set;
	i = 0;
	while (tmp2[i] != '\0')
	{
		if (tmp1 == tmp2[i])
			return (1);
		i++;
	}
	return (0);
}

int		start_and_end(char const *str, char const *set, int tmp)
{
	int		i;

	if (tmp == 1)
	{
		i = 0;
		while (cmp_set(str[i], set) && str[i] != '\0')
			i++;
	}
	else
	{
		i = ft_strlen(str) - 1;
		while (cmp_set(str[i], set))
			i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp1;
	char	*result;
	int		i;
	int		j;
	int		a;

	tmp1 = (char*)s1;
	i = start_and_end(tmp1, set, 1);
	a = 0;
	if (tmp1[i] == '\0')
	{
		if (!(result = (char*)malloc(1)))
			return (0);
		result[0] = 0;
		return (result);
	}
	j = start_and_end(tmp1, set, -1);
	if (!(result = (char*)malloc(j - i + 2)))
		return (0);
	while (i <= j)
		result[a++] = tmp1[i++];
	result[a] = '\0';
	return (result);
}
