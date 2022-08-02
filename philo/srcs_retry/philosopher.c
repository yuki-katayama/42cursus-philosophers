#include "philosopher_retry.h"

void *ft_philosopher(void *arg)
{
	t_philo *philo;

	(void)arg;

	philo = arg;
	printf("%d: %d %ld %ld %ld %ld\n", philo->id, philo->data->num_philo, philo->data->action_time.time_die, philo->data->action_time.time_eat, philo->data->action_time.time_sleep, philo->data->limit_eats);
	usleep(1000000);
	return (NULL);
}