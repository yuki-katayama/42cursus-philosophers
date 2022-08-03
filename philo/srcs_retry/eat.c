#include "philosopher_retry.h"

int8_t ft_eat(t_philo *philo)
{

	philo->time_last_eat = ft_gettime();
	ft_print_status(philo, EAT);
	if (ft_usleep(philo->data->action_time.time_eat) == ERROR) {
		return (ERROR);
	}
	return (0);
}