/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:26:15 by wokim             #+#    #+#             */
/*   Updated: 2021/05/19 13:39:55 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char *p2;

	p1 = dst;
	p2 = src;
	if (!p1 && !p2)
		return (0);
	while (n-- > 0)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	return (dst);
}
