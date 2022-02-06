/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:15:51 by kim-wonjin        #+#    #+#             */
/*   Updated: 2021/08/30 13:30:07 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_space(int space)
{
	int		ret;
	char	padding;

	padding = ' ';
	ret = 0;
	while (space-- > 0)
		ret += write(1, &padding, 1);
	return (ret);
}

int	print_char(char c, t_info *info)
{
	int	ret;
	int	space;

	ret = 0;
	space = info->width - 1;
	ret += print_space(space);
	ret += write(1, &c, 1);
	return (ret);
}

int	print_string(char *str, t_info *info)
{
	int	ret;
	int	space;
	int	len;
	int	i;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	space = info->width - len;
	ret += print_space(space);
	i = 0;
	while (i < len)
	{
		ret += write(1, &str[i++], 1);
	}
	return (ret);
}
