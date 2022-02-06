/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 05:39:22 by wokim             #+#    #+#             */
/*   Updated: 2022/02/07 00:58:08 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	i = 0;
	while (len--)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
