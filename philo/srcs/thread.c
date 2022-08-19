#include "philosopher_retry.h"

int8_t ft_thread_create(t_data *data, t_philo *philo) {
	int8_t i = -1;
	int64_t j = 0;
	while(++i != 2) {
		while(j < data->num_philo)
		{
			philo[j].id = j + 1;
			philo[j].data = data;
			philo[j].time_last_eat = -1;
			philo[j].can_max_eat_times = data->at_least_eat_times;
			if (pthread_create(&data->th_philo[j], NULL, ft_philosopher, &philo[j])
			|| pthread_create(&data->th_monitor[j], NULL, ft_monitor, &philo[j]))
				return (ft_error(E_PTHREAD_CREATE));
			j += 2;
		}
		usleep(1000);
		j = 1;
	}
	return (0);
}

int8_t ft_thread_end(t_data *data, t_philo *philo)
{
	int32_t	i = -1;
	while(++i < data->num_philo) {
		if(pthread_join(data->th_philo[i], NULL)
		|| pthread_join(data->th_monitor[i], NULL))
			return (ft_error(E_PTHREAD_JOIN));
	}
	free(data->th_philo);
	free(data->th_monitor);
	free(data->mtx_forks);
	free(philo);
	return (0);
}