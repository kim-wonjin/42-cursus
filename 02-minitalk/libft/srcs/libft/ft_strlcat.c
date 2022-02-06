/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:55:23 by wokim             #+#    #+#             */
/*   Updated: 2022/02/07 00:57:09 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	if (destlen > dstsize)
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
