/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:45:04 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:45:05 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*result;
	char	*start;

	result = (char*)dst;
	start = (char*)src;
	if (!dst && !src)
		return (0);
	while (n--)
	{
		*result++ = *start++;
	}
	return (dst);
}
