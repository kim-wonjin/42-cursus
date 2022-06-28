/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:46:17 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:46:18 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	while (len != 0 && s[len] != (char)c)
		len--;
	if (s[len] == (char)c)
		return ((char*)&s[len]);
	return (0);
}
