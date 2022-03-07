/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:57:58 by chansong          #+#    #+#             */
/*   Updated: 2022/03/07 16:22:57 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_pos_fd(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			putnbr_pos_fd(-n, fd);
		}
		else
			putnbr_pos_fd(n, fd);
	}
}
