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

typedef struct s_info
{
	bool			limit_eats_mode;
	bool			valid_write;
	size_t			num_philo;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	died;
	pthread_mutex_t	writing;
	pthread_t		*threads;
	t_time			times;
}				t_info;

//init
int			ft_init(t_info *info, char **argv);

//forks
int			ft_take_forks(t_philo *philo);
int			ft_down_forks(t_philo *philo);

//eat
int			ft_eat(t_philo *philo);

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
int			ft_m_unlock(pthread_mutex_t *m, pthread_mutex_t *m_died);
int			ft_m_lock(pthread_mutex_t *m, pthread_mutex_t *m_died);
int			ft_action_usleep(long int limit_time, t_philo *philo);

#endif