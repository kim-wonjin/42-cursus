/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 05:39:22 by wokim             #+#    #+#             */
/*   Updated: 2021/05/17 22:09:22 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	if (!(result = malloc(sizeof(char) * len + 1)))
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
