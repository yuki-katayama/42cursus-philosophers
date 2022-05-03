/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:43 by kyuki             #+#    #+#             */
/*   Updated: 2022/04/11 14:41:55 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h> //printf
# include <pthread.h> //pthread
# include <unistd.h> //usleep
# include <stdlib.h> //malloc
# include <sys/time.h> //gettimeofday
# include <stdbool.h> //bool
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define MICRO_TO_MILLI 1000
# define STOP_TEMPORALY 100
# define MAX_PTHREAD 31000
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEAD 5

typedef struct s_time
{
	long int	time_die;
	int			time_eat;
	int			time_sleep;
}				t_time;

struct	s_info;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*eating_m;
	long int		time_last_eat;
	int				eating;
	int				limit_eats;
	struct s_info	*info;
}				t_philo;

typedef struct s_status
{
	pthread_mutex_t	finish_m;
	pthread_mutex_t	writing;
	pthread_mutex_t	philos_died_m;
	size_t			philos_died;
	size_t			philos_limit_eats;
	bool			died;
	bool			limit_eats_mode;
}				t_status;

typedef struct s_info
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	size_t			num_philo;
	t_status		status;
	t_philo			*philo;
	t_time			times;
}				t_info;

//init
int			ft_init(t_info *info, char **argv);

//forks
int			ft_take_forks(t_philo *philo);
int			ft_down_forks(t_philo *philo);

//eat
int			ft_eat(t_philo *philo);
int ft_eat_action(t_philo *philo);

//output
int			ft_output(t_philo *philo, int serial);

//monitor
void		*ft_monitor(void *p);
int			ft_start_monitor(t_philo *philo);

// error
int			ft_error(int errno);

// exit
void		ft_exit(t_info *info);

// utils
long int	ft_gettime(t_philo *philo);
int			ft_m_unlock(pthread_mutex_t *m, pthread_mutex_t *finish_m);
int			ft_m_lock(pthread_mutex_t *m, pthread_mutex_t *finish_m);
int			ft_action_usleep(long int limit_time, t_philo *philo);
int  after_dead(t_info *info);
int ft_usleep(useconds_t usec, pthread_mutex_t *m);
void do_mtx(void *arg, pthread_mutex_t *m, int (*func)());

#endif