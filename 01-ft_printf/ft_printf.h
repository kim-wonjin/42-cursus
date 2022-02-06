/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:22:32 by kim-wonjin        #+#    #+#             */
/*   Updated: 2021/08/30 04:01:12 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct s_info
{
	int		width;
	char	type;
	int		num_base;
	int		num_sign;
}			t_info;

void	init_info(t_info *info);
int		print_by_type(va_list *ap, t_info *info);
void	manage_form(const char **form, t_info *info);
int		ft_printf(const char *form, ...);

int		print_space(int space);
int		print_char(char c, t_info *info);
int		print_string(char *str, t_info *info);

int		get_numlen(size_t num, int base);
char	*get_baseset(char type);
int		print_num_by_base(size_t num, t_info *info, int len);
int		print_num_by_type(size_t num, t_info *info, int len);
int		print_num(size_t num, t_info *info);

#endif
