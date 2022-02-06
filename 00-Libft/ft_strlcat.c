/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:55:23 by wokim             #+#    #+#             */
/*   Updated: 2021/05/19 16:59:03 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t destlen;
	size_t srclen;

	srclen = ft_strlen(src);
	if ((destlen = ft_strlen(dst)) > dstsize)
		destlen = dstsize;
	if (destlen == dstsize)
		return (dstsize + srclen);
	if (srclen < dstsize - destlen)
	{
		ft_memcpy(dst + destlen, src, srclen);
		dst[destlen + srclen] = '\0';
	}
	else
	{
		ft_memcpy(dst + destlen, src, dstsize - destlen - 1);
		dst[dstsize - 1] = '\0';
	}
	return (destlen + srclen);
}
