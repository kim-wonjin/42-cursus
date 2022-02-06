/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:18:35 by wokim             #+#    #+#             */
/*   Updated: 2021/05/07 20:16:45 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p1;
	const unsigned char *p2;

	p1 = dst;
	p2 = src;
	if (!p1 && !p2)
		return (0);
	if (dst < src)
		while (len-- > 0)
			*p1++ = *p2++;
	else
	{
		p1 += len;
		p2 += len;
		while (len-- > 0)
			*(--p1) = *(--p2);
	}
	return (dst);
}
