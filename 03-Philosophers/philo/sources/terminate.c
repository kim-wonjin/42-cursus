/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:01:19 by wokim             #+#    #+#             */
/*   Updated: 2022/04/26 20:01:22 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_usage(void)
{
	ft_putstr_fd("usage : ./philo number_of_philosophers ", STDERR_FILENO);
	ft_putstr_fd("time_to_die time_to_eat time_to_sleep ", STDERR_FILENO);
	ft_putendl_fd("[number_of_times_each_philosopher_must_eat]", STDERR_FILENO);
}

static void	destroy_mutex(t_info *info)
{
	int	i;

	if (info->fork)
	{
		i = 0;
		while (i < info->nbr_philo)
		{
			pthread_mutex_destroy(&info->fork[i]);
			++i;
		}
	}
	pthread_mutex_destroy(&info->dining);
	pthread_mutex_destroy(&info->print);
}

t_exit	terminate(int validation, t_info *info)
{
	if (info)
		destroy_mutex(info);
	if (errno != 0)
		perror("philo");
	if (validation == INVALID)
		return (INVALID);
	else
		return (VALID);
}
