/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:55 by wokim             #+#    #+#             */
/*   Updated: 2022/04/26 20:02:57 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_fork(t_info *info)
{
	if (sem_wait(info->sem_fork) == ERROR || \
		print_status(info, TAKEN) == false || \
		sem_wait(info->sem_fork) == ERROR || \
		print_status(info, TAKEN) == false)
		sem_post(info->sem_dining);
}

void	put_fork(t_info *info)
{
	if (sem_post(info->sem_fork) == ERROR || \
		sem_post(info->sem_fork) == ERROR)
		sem_post(info->sem_dining);
}

void	philo_eat(t_info *info)
{
	if (timestamp(&info->philo[info->i].cur) == false || \
		print_status(info, EATING) == false)
		sem_post(info->sem_dining);
	wait_interval(info, info->philo[info->i].cur, info->time_eat);
	++(info->philo[info->i].cnt_eat);
	if (info->philo[info->i].cnt_eat == info->nbr_eat)
		if (sem_post(info->sem_full) == ERROR)
			sem_post(info->sem_dining);
}

void	philo_sleep(t_info *info)
{
	long long	cur;

	cur = 0;
	if (timestamp(&cur) == false || \
		print_status(info, SLEEPING) == false)
		sem_post(info->sem_dining);
	wait_interval(info, cur, info->time_sleep);
}

void	philo_think(t_info *info)
{
	if (print_status(info, THINKING) == false)
		sem_post(info->sem_dining);
}
