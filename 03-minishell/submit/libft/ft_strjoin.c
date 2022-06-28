/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:45:45 by sshin             #+#    #+#             */
/*   Updated: 2022/06/27 00:15:50 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_length(int *i, int *j, char const *s1, char const *s2)
{
	while (s1[*i])
		(*i)++;
	while (s2[*j])
		(*j)++;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	i = 0;
	j = 0;
	ft_length(&i, &j, s1, s2);
	result = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!result)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j])
		result[i++] = s2[j];
	result[i] = 0;
	return (result);
}
