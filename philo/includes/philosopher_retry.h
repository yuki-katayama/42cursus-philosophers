#ifndef PHILOSOPHER_RETRY_H
# define PHILOSOPHER_RETRY_H

# include <stdio.h> //printf
# include <limits.h>
# include <stdint.h>

# include <pthread.h> //pthread
# include <unistd.h> //usleep
# include <stdlib.h> //malloc
# include <sys/time.h> //gettimeofday
# include <stdbool.h> //bool
# include "libft.h"

#define ERROR 1
#define PHILO_MIN 1
#define PHILO_MAX 200
#define TIME_DIE_MIN 5
#define TIME_EAT_MIN 1
#define TIME_SLEEP_MIN 1

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0;0m"

enum	e_error {
	E_INVALID_NUM_ARGUMENTS = 1,
	E_INVALID_ARGUMENT,
	E_MALLOCK,
	E_MUTEX_INIT,
	E_GET_TIME_OF_DAY,
	E_USLEEP,
	// E_PTHREAD_CREATE,
	// E_PTHREAD_DETACH,
	// E_MUTEX_LOCK,
	// E_MUTEX_UNLOCK,
};

enum	e_status {
	FORK = 1,
	EAT,
	SLEEP,
	THINK,
	DEAD
};

typedef struct s_time
{
	int64_t	time_die;
	int64_t	time_eat;
	int64_t	time_sleep;
}				t_time;

typedef struct	s_data
{
	pthread_t *th_philo;
	pthread_t *th_monitor;
	pthread_mutex_t *forks;
	int32_t num_philo;
	int64_t limit_eats;
	t_time	action_time;
}				t_data;

typedef struct s_philo {
	int32_t			id;
	t_data			*data;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int64_t			time_last_eat;
}				t_philo;


//error
int8_t ft_error(int32_t errno);

// init
int8_t ft_validate_arg(t_data *data);
int8_t ft_init_forks(t_philo *philo);
int8_t ft_init(t_data *data, t_philo **philo, char **argv);

// philosopher
void *ft_philosopher(void *arg);

// thread
int8_t ft_thread_end(t_data *data, t_philo *philo);
int8_t ft_thread_create(t_data *data, t_philo *philo);

// utils
int64_t	philo_atoi(const char *str);
int8_t ft_usleep(int64_t time);
int64_t	ft_gettime(void);

// eat
int8_t ft_eat(t_philo *philo);

// fork
void ft_take_fork(t_philo *philo);
void ft_down_fork(t_philo *philo);

// eat
int8_t ft_sleep(t_philo *philo);

//output
void	ft_print_status(t_philo *philo, int8_t action);

#endif