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

typedef struct	s_data
{
	pthread_t *th_philo;
	pthread_t *th_monitor;
	int64_t num_philo;
	int64_t limit_eats;
	int64_t time_die;
	int64_t time_eat;
	int64_t time_sleep;
}				t_data;

typedef struct s_philo {
	int			id;
	pthread_mutex_t forks;
	t_data			*data;
}				t_philo;

int64_t			philo_atoi(const char *str);


#endif