/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:26:15 by wokim             #+#    #+#             */
/*   Updated: 2022/02/07 00:51:59 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;

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
