/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:45:32 by wokim             #+#    #+#             */
/*   Updated: 2021/05/19 13:28:42 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*p1;
	const unsigned char		*p2;

	p1 = dst;
	p2 = src;
	if (!p1 && !p2)
		return (0);
	while (n-- > 0)
	{
		*p1 = *p2;
		if (*p1 == (unsigned char)c)
		{
			p1++;
			return (p1);
		}
		p1++;
		p2++;
	}
	return (0);
}
