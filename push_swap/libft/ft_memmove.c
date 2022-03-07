/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:57:27 by chansong          #+#    #+#             */
/*   Updated: 2022/03/07 16:22:46 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = src;
	temp = dest;
	if (dest <= src)
	{
		while (n--)
			*temp++ = *s++;
	}
	else
	{
		s += n;
		temp += n;
		while (n--)
			*--temp = *--s;
	}
	return (dest);
}
