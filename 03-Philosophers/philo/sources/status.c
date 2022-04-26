/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:01:12 by wokim             #+#    #+#             */
/*   Updated: 2022/04/26 20:01:15 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->info->fork[philo->l]) || \
		print_status(TAKEN, philo) == false || \
		pthread_mutex_lock(&philo->info->fork[philo->r]) || \
		print_status(TAKEN, philo) == false)
		pthread_mutex_unlock(&philo->info->dining);
}

void	put_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->info->fork[philo->l]) || \
		pthread_mutex_unlock(&philo->info->fork[philo->r]))
		pthread_mutex_unlock(&philo->info->dining);
}

void	philo_eat(t_philo *philo)
{
	if (timestamp(&(philo->cur)) == false || \
		print_status(EATING, philo) == false)
		pthread_mutex_unlock(&philo->info->dining);
	wait_interval(philo, philo->cur, philo->info->time_eat);
	++(philo->cnt_eat);
	if (philo->cnt_eat == philo->info->nbr_eat)
	{
		++(philo->info->cnt_full);
		if (philo->info->cnt_full >= philo->info->nbr_philo)
			if (print_status(COMPLETE, philo) == false)
				pthread_mutex_unlock(&philo->info->dining);
	}
}

void	philo_sleep(t_philo *philo)
{
	long long	cur;

	cur = 0;
	if (timestamp(&cur) == false || \
		print_status(SLEEPING, philo) == false)
		pthread_mutex_unlock(&philo->info->dining);
	wait_interval(philo, cur, philo->info->time_sleep);
}

void	philo_think(t_philo *philo)
{
	if (print_status(THINKING, philo) == false)
		pthread_mutex_unlock(&philo->info->dining);
}
