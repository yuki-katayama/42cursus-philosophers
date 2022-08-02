#include "philosopher_retry.h"

int8_t ft_thread_create(t_data *data, t_philo *philo) {
	int64_t i = -1;
	while(++i < data->num_philo) 
	{
		philo[i].id = i + 1;
		philo[i].data = data;
	}
	i = -1;
	while(++i < data->num_philo) {
		ft_init_forks(&philo[i]);
		pthread_create(&data->th_philo[i], NULL, ft_philosopher, &philo[i]);
	}
	return (0);
}

int8_t ft_thread_end(t_data *data, t_philo *philo)
{
	int32_t	i = -1;
	while(++i < data->num_philo) {
		pthread_join(data->th_philo[i], NULL);
	}
	free(data->th_philo);
	free(data->th_monitor);
	free(data->forks);
	free(philo);
	return (0);
}