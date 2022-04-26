/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:35 by wokim             #+#    #+#             */
/*   Updated: 2022/04/26 20:02:38 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/stat.h>

static bool	open_sem(sem_t **sem, const char *name, size_t nbr_lock)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT, 0644, nbr_lock);
	if (*sem == SEM_FAILED)
		return (false);
	return (true);
}

static bool	init_info(int ac, char **av, t_info *info)
{
	if (atoi_bool(av[1], &(info->nbr_philo)) == false || \
		atoi_bool(av[2], &(info->time_die)) == false || \
		atoi_bool(av[3], &(info->time_eat)) == false || \
		atoi_bool(av[4], &(info->time_sleep)) == false || \
		(ac == 6 && atoi_bool(av[5], &(info->nbr_eat)) == false))
		return (false);
	info->philo = ft_calloc(info->nbr_philo, sizeof(t_philo));
	if (info->philo == NULL)
		return (false);
	info->dining = "/sem_dining";
	info->fork = "/sem_fork";
	info->print = "/sem_print";
	info->full = "/sem_full";
	if (open_sem(&info->sem_dining, info->dining, 0) == false || \
		open_sem(&info->sem_fork, info->fork, info->nbr_philo) == false || \
		open_sem(&info->sem_print, info->print, 1) == false || \
		open_sem(&info->sem_full, info->full, 0) == false)
		return (false);
	return (true);
}

static void	routine(t_info *info)
{
	if (timestamp(&info->philo[info->i].cur) == false)
		sem_post(info->sem_dining);
	if (info->i % 2)
		wait_interval(info, info->philo[info->i].cur, 10 * EPSILON);
	while (1)
	{
		take_fork(info);
		philo_eat(info);
		put_fork(info);
		philo_sleep(info);
		philo_think(info);
	}
}

static bool	feed_philo(t_info *info)
{
	int	i;

	if (pthread_create(&info->th, NULL, monitor_full, (void *)info) || \
		pthread_detach(info->th) || timestamp(&info->start) == false)
		return (false);
	i = 0;
	while (i < info->nbr_philo)
	{
		info->i = i;
		info->philo[i].pid = fork();
		if (info->philo[i].pid == ERROR)
			return (false);
		else if (info->philo[i].pid == 0)
		{
			if (pthread_create(&info->philo[info->i].th, NULL, monitor_death, \
				info) || pthread_detach(info->philo[info->i].th))
				sem_post(info->sem_dining);
			routine(info);
			exit(VALID);
		}
		++i;
	}
	if (sem_wait(info->sem_dining) == ERROR)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_info	info;

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
	if (feed_philo(&info) == false)
		return (terminate(INVALID, &info));
	return (terminate(VALID, &info));
}
