/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 03:39:00 by wokim             #+#    #+#             */
/*   Updated: 2022/02/07 00:48:15 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = ft_strlen(needle);
	while (*haystack && len-- >= i)
	{
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, i) == 0)
				return ((char *)haystack);
		haystack++;
	}
	return (0);
}
