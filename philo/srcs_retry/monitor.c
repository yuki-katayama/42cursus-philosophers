#include "philosopher_retry.h"

int8_t check_died(t_philo *philo)
{
	int64_t elapsed_time;

	elapsed_time = ft_gettime() - philo->time_last_eat;
	if(philo->time_last_eat != -1 && elapsed_time >= philo->data->action_time.time_die) {
		ft_print_status(philo, DIED);
		philo->data->died = 1;
	}
	return (0);
}

int8_t continue_monitor(t_philo *philo)
{
	check_died(philo);
	return (is_alive(philo));
}

void *ft_monitor(void *arg)
{
	t_philo *philo;

	philo = arg;
	while(continue_monitor(philo)) {
		if (philo->data->died == 1)
			return (NULL);
		if (ft_usleep(200))
			return (NULL);
	}
	return (NULL);
}