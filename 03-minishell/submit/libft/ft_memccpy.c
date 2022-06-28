/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:44:50 by sshin             #+#    #+#             */
/*   Updated: 2022/06/27 00:11:05 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*result;
	char	*start;
	char	tmp;

	result = (char *)dst;
	start = (char *)src;
	tmp = (unsigned char)c;
	if (!dst && !src)
		return (0);
	while (n--)
	{
		*result++ = *start;
		if (*start++ == tmp)
			return (result);
	}
	return (0);
}
