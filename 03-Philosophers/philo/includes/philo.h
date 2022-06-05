/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:59:59 by wokim             #+#    #+#             */
/*   Updated: 2022/05/19 21:15:23 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>

# define EPSILON	1000
# define MILLI		1000
# define ERROR		-1

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mu;

typedef enum e_exit
{
	VALID,
	INVALID,
}			t_exit;

typedef enum e_cond
{
	TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	COMPLETE,
}			t_status;

typedef struct s_info
{
	int			nbr_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			nbr_eat;
	int			cnt_full;
	t_mu		*fork;
	t_mu		print;
	t_mu		dining;
	long long	start;
}				t_info;

typedef struct s_philo
{
	int			i;
	int			l;
	int			r;
	int			cnt_eat;
	t_th		routine;
	t_th		monitor;
	t_info		*info;
	long long	cur;
}				t_philo;

/*
** =============================================================================
** exit.c
** =============================================================================
*/

void	print_usage(void);
t_exit	terminate(int validation, t_info *info);

/*
** =============================================================================
** print.c
** =============================================================================
*/

bool	print_status(t_status, t_philo *);

/*
** =============================================================================
** status.c
** =============================================================================
*/

void	take_fork(t_philo *philo);
void	put_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/*
** =============================================================================
** time.c
** =============================================================================
*/

bool	timestamp(long long *time_to_stamp);
void	wait_interval(t_philo *philo, long long start, long long interval);

/*
** =============================================================================
** libft
** =============================================================================
*/

void	*ft_calloc(size_t cnt, size_t size);
void	mdealloc(void **ptr);
int		ft_atoi(const char *str);
bool	atoi_bool(const char *str, int *ifroma);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
