/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:34:18 by wokim             #+#    #+#             */
/*   Updated: 2022/02/07 01:13:02 by kim-wonjin       ###   ########.fr       */
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

char	*ft_itoa(int n)
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
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[len--] = '\0';
	result[0] = '-';
	result[len--] = tmp % 10 + '0';
	tmp /= 10;
	while (tmp)
	{
		result[len--] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (result);
}
