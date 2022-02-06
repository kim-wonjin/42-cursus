/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:34:18 by wokim             #+#    #+#             */
/*   Updated: 2021/05/17 17:07:24 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rec(int n)
{
	if (n == 0)
		return (0);
	else
		return (1 + rec(n / 10));
}

char		*ft_itoa(int n)
{
	char			*result;
	int				len;
	unsigned int	tmp;

	len = 1 + rec(n / 10);
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	else
		tmp = n;
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len--] = '\0';
	if (n < 0)
		result[0] = '-';
	result[len--] = tmp % 10 + '0';
	while (tmp /= 10)
		result[len--] = tmp % 10 + '0';
	return (result);
}
