/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:20 by wokim             #+#    #+#             */
/*   Updated: 2022/04/26 20:02:22 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	ft_isspc(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (true);
	return (false);
}

static bool	ft_isnbr(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

static bool	ft_isplusminus(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	ret;

	sign = 1;
	ret = 0;
	while (ft_isspc(*str))
		++str;
	if (ft_isplusminus(*str))
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (ft_isnbr(*str))
	{
		ret *= 10;
		ret += (*str - '0');
		++str;
	}
	if (sign > 0 && ret > 9223372036854775807llu)
		return (-1);
	if (sign < 0 && ret > 9223372036854775808llu)
		return (0);
	return (sign * ((int)ret));
}

bool	atoi_bool(const char *str, int *ifroma)
{
	int		sign;
	size_t	ret;

	sign = 1;
	ret = 0;
	while (ft_isspc(*str) == true)
		++str;
	if (ft_isplusminus(*str) == true)
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str)
	{
		if (ft_isnbr(*str) == false)
			return (false);
		ret *= 10;
		ret += (*str - '0');
		++str;
	}
	*ifroma = sign * ((int)ret);
	return (true);
}
