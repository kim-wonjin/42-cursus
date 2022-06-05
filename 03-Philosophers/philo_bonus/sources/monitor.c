/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:42 by wokim             #+#    #+#             */
/*   Updated: 2022/05/19 22:30:37 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_full(void *ptr_info)
{
	int		cnt_full;
	t_info	*info;

	cnt_full = 0;
	info = (t_info *)ptr_info;
	while (1)
	{
		if (sem_wait(info->sem_full) == ERROR)
			sem_post(info->sem_dining);
		++cnt_full;
		if (cnt_full >= info->nbr_philo)
		{
			print_status(info, COMPLETE);
			sem_post(info->sem_dining);
		}
	}
	return (NULL);
}

void	*monitor_death(void *ptr_info)
{
	t_info		*info;
	long long	cur;

	info = (t_info *)ptr_info;
	if (timestamp(&cur) == false)
		sem_post(info->sem_dining);
	wait_interval(info, cur, info->time_die / 2);
	while (1)
	{
		if (timestamp(&cur) == false)
			sem_post(info->sem_dining);
		if (cur - info->philo[info->i].cur >= (long long)info->time_die)
		{
			print_status(info, DIED);
			sem_post(info->sem_dining);
		}
		usleep(5000);
	}
	return (NULL);
}
