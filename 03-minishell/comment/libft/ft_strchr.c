/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:45:37 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:45:38 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (i != len && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char*)&s[i]);
	return (0);
}
