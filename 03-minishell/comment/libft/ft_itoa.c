/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:44:08 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:44:09 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int n)
{
	int		result;

	if (n < 0)
		result = -1 * n;
	else
		result = n;
	return (result);
}

int		cal_size(int n)
{
	int		size;
	int		tmp;

	size = 1;
	tmp = n;
	if (n < -9)
		size++;
	if (n < 0)
	{
		size++;
		tmp = ft_abs(tmp / 10);
	}
	while (tmp > 9)
	{
		size++;
		tmp = tmp / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	int		flag;

	flag = 0;
	size = cal_size(n);
	if (!(result = (char*)malloc(size + 1)))
		return (0);
	result[size--] = '\0';
	if (n < 0)
		flag = 1;
	while (size >= 0)
	{
		result[size] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		size--;
	}
	if (flag == 1)
		result[0] = '-';
	return (result);
}
