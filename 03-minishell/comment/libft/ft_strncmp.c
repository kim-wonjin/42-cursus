/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:46:09 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:46:09 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	if (t1 == NULL || t2 == NULL)
		return (-1);
	while (t1[i] != '\0' && t2[i] != '\0' && i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		else
			i++;
	}
	if (t1[i] != '\0' && i < n)
		return (t1[i]);
	if (t2[i] != '\0' && i < n)
		return (-t2[i]);
	return (0);
}
