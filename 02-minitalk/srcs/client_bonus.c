/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:36:45 by wokim             #+#    #+#             */
/*   Updated: 2022/02/09 15:06:48 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk_bonus.h"

void	sendsig(int id, int num)
{
	if (num)
		kill(id, SIGUSR1);
	else
		kill(id, SIGUSR2);
}

void	sendbitnum(int id, int num)
{
	int	bit;

	bit = 128;
	while (bit)
	{
		sendsig(id, bit & num);
		bit = bit >> 1;
		usleep(100);
	}
}

void	sigtest(char *pid, char *str)
{
	int	bit;
	int	id;

	id = ft_atoi(pid);
	while (str && ft_strlen(str))
	{
		bit = 128;
		while (bit)
		{
			sendsig(id, bit & *str);
			bit = bit >> 1;
			usleep(100);
		}
		str++;
	}
	sendbitnum(id, 255);
	return ;
}

void	success_ack(int signo)
{
	if (signo == SIGUSR1)
		write(1, "ACK SUCCESS!\n", 14);
	exit(0);
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, success_ack);
	if (argc != 3)
	{
		write(1, "Usage : ", 8);
		write(1, argv[0], ft_strlen(argv[0]));
		write(1, " PID MESSAGE\n", 13);
		exit(0);
	}
	else
		sigtest(argv[1], argv[2]);
	sleep(1);
	write(1, "over 1sec\n", 10);
	return (0);
}
