/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:43 by kyuki             #+#    #+#             */
/*   Updated: 2022/05/10 22:25:49 by kyuki            ###   ########.fr       */
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
# include "libft.h"

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define MICRO_TO_MILLI 1000
# define STOP_TEMPORALY 100
# define MAX_PTHREAD 31000

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define DEFAULT "\033[0;0m"

enum e_error {
	E_MALLOCK = 1,
	E_MUTEX_INIT,
	E_INVALID_ARGUMENT,
	E_PTHREAD_CREATE,
	E_PTHREAD_DETACH,
	E_MUTEX_LOCK,
	E_MUTEX_UNLOCK,
	E_USLEEP,
	E_INVALID_NUM_ARGUMENTS,
	E_GET_TIME_OF_DAY,
};

enum e_status {
	FORK = 1,
	EAT,
	SLEEP,
	THINK,
	DEAD
};


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
int	ft_atoi(const char *str);

#endif
