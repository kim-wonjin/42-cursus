/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:56:30 by chansong          #+#    #+#             */
/*   Updated: 2022/03/07 16:22:08 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
	}
	return (str);
}

static char	*get_arr(char *res, int n, size_t len, size_t sign)
{
	size_t	i;

	i = 0;
	res[len + sign] = '\0';
	if (n == 0)
		res[i] = '0';
	else
	{
		while (n > 0)
		{
			res[i++] = n % 10 + '0';
			n /= 10;
		}
		if (sign == 1)
			res[i] = '-';
		res = ft_strrev(res);
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	sign;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	len = n_len(n);
	res = (char *)malloc(len + sign + 1);
	if (!res)
		return (NULL);
	res = get_arr(res, n, len, sign);
	return (res);
}
