/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:22:27 by kim-wonjin        #+#    #+#             */
/*   Updated: 2021/08/30 16:52:16 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->width = 0;
	info->type = 0;
	info->num_base = 16;
	info->num_sign = 1;
}

int	print_by_type(va_list *ap, t_info *info)
{
	int	ret;

	ret = 0;
	if (info->type == 'c')
		ret = print_char(va_arg(*ap, int), info);
	else if (info->type == 's')
		ret = print_string(va_arg(*ap, char *), info);
	else if (info->type == 'p')
		ret = print_num(va_arg(*ap, unsigned long), info);
	else if (info->type == 'd' || info->type == 'i')
		ret = print_num(va_arg(*ap, int), info);
	else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		ret = print_num(va_arg(*ap, unsigned int), info);
	else if (info->type == '%')
		ret = print_char('%', info);
	return (ret);
}

void	manage_form(const char **form, t_info *info)
{	
	init_info(info);
	while (**form != '\0' && !(ft_strchr(TYPE, **form)))
	{
		if (ft_isdigit(**form))
			info ->width = info->width * 10 + **form - '0';
		++(*form);
	}
	info->type = **form;
}

int	ft_printf(const char *form, ...)
{
	int			ret;
	va_list		ap;
	t_info		info;

	va_start(ap, form);
	ret = 0;
	while (*form)
	{
		if (*form != '%')
			ret += write(1, form, 1);
		else
		{
			form++;
			manage_form(&form, &info);
			ret += print_by_type(&ap, &info);
		}
		form++;
	}
	va_end(ap);
	return (ret);
}
