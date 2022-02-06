/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:39:16 by wokim             #+#    #+#             */
/*   Updated: 2022/02/07 00:56:21 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (s1[len - 1] && ft_strchr(set, s1[len - 1]) && len)
		len--;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	ft_memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}
