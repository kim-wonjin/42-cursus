/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:57:10 by chansong          #+#    #+#             */
/*   Updated: 2022/03/07 16:22:36 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
	{
		*temp = *s;
		if (*s == (unsigned char)c)
			return (temp + 1);
		temp++;
		s++;
	}
	return (NULL);
}
