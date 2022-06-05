/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:00:49 by wokim             #+#    #+#             */
/*   Updated: 2022/05/19 21:31:23 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_info(int ac, char **av, t_info *info)
{
	int	i;

	if (atoi_bool(av[1], &(info->nbr_philo)) == false || \
		atoi_bool(av[2], &(info->time_die)) == false || \
		atoi_bool(av[3], &(info->time_eat)) == false || \
		atoi_bool(av[4], &(info->time_sleep)) == false || \
		(ac == 6 && atoi_bool(av[5], &(info->nbr_eat)) == false))
		return (false);
	info->fork = ft_calloc(info->nbr_philo, sizeof(t_mu));
	if (info->fork == NULL)
		return (false);
	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (false);
		++i;
	}
	if (pthread_mutex_init(&info->dining, NULL) || \
		pthread_mutex_init(&info->print, NULL))
		return (false);
	return (true);
}

static void	*routine(void *ptr_ith_philo)
{
	t_philo	*philo;

	philo = (t_philo *)ptr_ith_philo;
	if (philo->i % 2)
		wait_interval(philo, philo->cur, 1);
	while (1)
	{
		take_fork(philo);
		philo_eat(philo);
		put_fork(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static void	*monitor(void *ptr_ith_philo)
{
	t_philo		*philo;
	long long	cur;

	philo = (t_philo *)ptr_ith_philo;
	if (timestamp(&cur) == false)
		pthread_mutex_unlock(&philo->info->dining);
	wait_interval(philo, cur, philo->info->time_die / 2);
	while (1)
	{
		if (timestamp(&cur) == false)
			pthread_mutex_unlock(&philo->info->dining);
		if (cur - philo->cur >= (long long)philo->info->time_die)
		{
			print_status(DIED, philo);
			pthread_mutex_unlock(&philo->info->dining);
		}
		usleep(5000);
	}
	return (NULL);
}

static bool	feed_philo(t_info *info, t_philo *philo)
{
	int	i;

	if (pthread_mutex_lock(&info->dining) || \
		timestamp(&info->start) == false)
		return (false);
	i = 0;
	while (i < info->nbr_philo)
	{
		philo[i].i = i;
		philo[i].info = info;
		philo[i].l = i;
		philo[i].r = (i + 1) % info->nbr_philo;
		if (timestamp(&philo[i].cur) == false)
			pthread_mutex_unlock(&philo->info->dining);
		if (pthread_create(&philo[i].routine, NULL, routine, &philo[i]) || \
			pthread_detach(philo[i].routine))
			return (false);
		if (pthread_create(&philo[i].monitor, NULL, monitor, &philo[i]) || \
			pthread_detach(philo[i].monitor))
			return (false);
		++i;
	}
	if (pthread_mutex_lock(&info->dining))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	errno = 0;
	if (!(ac == 5 || ac == 6) || (ac == 6 && ft_atoi(av[5]) == 0))
	{
		print_usage();
		return (terminate(INVALID, NULL));
	}
	info = (t_info){0, };
	if (init_info(ac, av, &info) == false)
	{
		print_usage();
		return (terminate(INVALID, &info));
	}
	philo = ft_calloc(info.nbr_philo, sizeof(t_philo));
	if (philo == NULL)
		return (terminate(INVALID, &info));
	if (feed_philo(&info, philo) == false)
		return (terminate(INVALID, &info));
	return (terminate(VALID, &info));
}
