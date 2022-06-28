/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:45:08 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:45:09 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcc;
	char	*dstc;
	size_t	i;

	i = 0;
	srcc = (char *)src;
	dstc = (char *)dst;
	if (!dst && !src)
		return (0);
	if (srcc < dstc)
		while (len > 0)
		{
			*(dstc + len - 1) = *(srcc + len - 1);
			len--;
		}
	else
		while (i < len)
		{
			*(dstc + i) = *(srcc + i);
			i++;
		}
	return (dst);
}
