/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:01:30 by wokim             #+#    #+#             */
/*   Updated: 2022/04/26 20:01:34 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	timestamp(long long *time_to_stamp)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (false);
	*time_to_stamp = (long long)(tv.tv_sec * MILLI + tv.tv_usec / MILLI);
	return (true);
}

void	wait_interval(t_philo *philo, long long start, long long interval)
{
	long long	cur;

	while (1)
	{
		if (timestamp(&cur) == false)
			pthread_mutex_unlock(&philo->info->dining);
		if (cur - start >= interval)
			break ;
		if (usleep(EPSILON) == ERROR)
			pthread_mutex_unlock(&philo->info->dining);
	}
}
