/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:44:44 by wokim             #+#    #+#             */
/*   Updated: 2022/02/09 14:37:31 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk_bonus.h"

void	endLine(int id)
{
	write(1, "\n", 1);
	kill(id, SIGUSR1);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static int		num;
	static int		ascii;

	(void)info;
	(void)context;
	if (ascii < 8)
	{
		num = num << 1;
		if (signo == SIGUSR1)
			num = num | 1;
		ascii++;
	}
	if (ascii >= 8)
	{
		if (num != 255)
			write(1, &num, 1);
		else
			endLine(info->si_pid);
		num = 0;
		ascii = 0;
	}
	return ;
}

int	main(void)
{
	struct sigaction	sigact;
	int					pid;
	char				*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	sigact.sa_sigaction = handler;
	sigact.sa_flags = SA_SIGINFO;
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
	free(pid_str);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
