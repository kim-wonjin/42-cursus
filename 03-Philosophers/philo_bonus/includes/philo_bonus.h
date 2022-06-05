/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:00 by wokim             #+#    #+#             */
/*   Updated: 2022/05/19 21:37:06 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>

# define EPSILON	1000
# define MILLI		1000
# define ERROR		-1

typedef pthread_t	t_th;

typedef enum e_exit
{
	VALID,
	INVALID,
}			t_exit;

typedef enum e_status
{
	TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	COMPLETE,
}			t_status;

typedef struct s_philo
{
	int			cnt_eat;
	t_th		th;
	pid_t		pid;
	long long	cur;
}				t_philo;

typedef struct s_info
{
	int			i;
	int			nbr_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			nbr_eat;
	char		*fork;
	char		*dining;
	char		*print;
	char		*full;
	t_th		th;
	sem_t		*sem_fork;
	sem_t		*sem_dining;
	sem_t		*sem_print;
	sem_t		*sem_full;
	t_philo		*philo;
	long long	start;
}				t_info;

/*
** =============================================================================
** monitor.c
** =============================================================================
*/
void	*monitor_full(void *ptr_info);
void	*monitor_death(void *ptr_info);

/*
** =============================================================================
** print.c
** =============================================================================
*/

bool	print_status(t_info *op, t_status cond);

/*
** =============================================================================
** status.c
** =============================================================================
*/

void	philo_eat(t_info *op);
void	philo_sleep(t_info *op);
void	philo_think(t_info *op);
void	take_fork(t_info *op);
void	put_fork(t_info *op);

/*
** =============================================================================
** terminate.c
** =============================================================================
*/

void	print_usage(void);
t_exit	terminate(int validation, t_info *info);

/*
** =============================================================================
** time.c
** =============================================================================
*/

bool	timestamp(long long *val);
void	wait_interval(t_info *op, long long begin, long long nbr_eat);

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
