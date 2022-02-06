/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:17:45 by kim-wonjin        #+#    #+#             */
/*   Updated: 2021/08/30 13:34:16 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_numlen(size_t num, int base)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num)
	{
		++len;
		num /= base;
	}
	return (len);
}

char	*get_baseset(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

int	print_num_by_base(size_t num, t_info *info, int len)
{
	char	*buf;
	size_t	backup;
	char	*baseset;
	int		ret;

	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (0);
	buf[len] = '\0';
	backup = num;
	baseset = get_baseset(info->type);
	while (len-- > 0)
	{
		buf[len] = baseset[num % info->num_base];
		num /= info->num_base;
	}
	ret = 0;
	ft_putstr_fd(buf, 1);
	ret += ft_strlen(buf);
	free(buf);
	return (ret);
}

int	print_num_by_type(size_t num, t_info *info, int len)
{
	int		ret;

	ret = 0;
	if (info->num_sign < 0)
		ret += write(1, "-", 1);
	if (info->type == 'p')
		ret += write(1, "0x", 2);
	ret += print_num_by_base(num, info, len);
	return (ret);
}

int	print_num(size_t num, t_info *info)
{
	int	ret;
	int	space;
	int	len;

	if (info->type == 'd' || info->type == 'i' || info->type == 'u')
		info->num_base = 10;
	if ((info->type == 'd' || info->type == 'i') && (int)num < 0)
	{
		info->num_sign = -1;
		num *= -1;
	}
	len = get_numlen(num, info->num_base);
	ret = 0;
	space = info->width - len;
	if (info->num_sign < 0)
		space -= 1;
	else if (info->type == 'p')
		space -= 2;
	ret += print_space(space);
	ret += print_num_by_type(num, info, len);
	return (ret);
}
