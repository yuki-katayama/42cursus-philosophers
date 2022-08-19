#include "philosopher.h"

static int8_t ft_init_arg(t_data *data, char **argv)
{
	data->num_philo = philo_atoi(argv[1]);
	data->action_time.time_die = philo_atoi(argv[2]);
	data->action_time.time_eat = philo_atoi(argv[3]);
	data->action_time.time_sleep = philo_atoi(argv[4]);
	data->at_least_eat_times = -1;
	data->at_least_eat_num_philo  = -1;
	if (argv[5] != NULL) {
		data->at_least_eat_num_philo = data->num_philo;
		data->at_least_eat_times = philo_atoi(argv[5]);
		if (data->at_least_eat_times < 0)
			return (ft_error(E_INVALID_ARGUMENT));
	}
	if ( data->num_philo < PHILO_MIN \
	|| data->num_philo > PHILO_MAX \
	|| data->action_time.time_die < TIME_DIE_MIN \
	|| data->action_time.time_eat < TIME_EAT_MIN \
	|| data->action_time.time_sleep < TIME_SLEEP_MIN)
		return (ft_error(E_INVALID_ARGUMENT));
	return (0);
}

static int8_t ft_init_malloc(t_data *data, t_philo **philo)
{
	if (!(ft_malloc_p((void **)&data->th_philo, sizeof(pthread_t) * data->num_philo))
	|| !(ft_malloc_p((void **)&data->th_monitor, sizeof(pthread_t) * data->num_philo))
	|| !(ft_malloc_p((void **)&data->mtx_forks, sizeof(pthread_mutex_t) * data->num_philo))
	|| !(ft_malloc_p((void **)&*philo, sizeof(t_philo) * data->num_philo)))
		return (ft_error(E_MALLOCK));
	return (0);
}

static int8_t ft_init_mutex(t_data *data)
{
	int32_t i;

	if (pthread_mutex_init(&data->mtx_print_status, NULL) != 0
	|| pthread_mutex_init(&data->mtx_died, NULL) != 0)
		return (ft_error(E_MUTEX_INIT));
	i = -1;
	while (++i < data->num_philo) {
		if (pthread_mutex_init(&data->mtx_forks[i], NULL) != 0)
			return (ft_error(E_MUTEX_INIT));
	}
	return (0);
}

int8_t ft_init(t_data *data, t_philo **philo, char **argv) {
	if(ft_init_arg(data, argv)
	|| ft_init_malloc(data, philo)
	|| ft_init_mutex(data))
		return (ERROR);
	return (0);
}