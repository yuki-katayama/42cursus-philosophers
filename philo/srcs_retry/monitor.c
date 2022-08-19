#include "philosopher_retry.h"

int8_t check_died(t_philo *philo)
{
	if(is_died(philo)) {
		do_mtx(&(t_print){philo, DIED}, &philo->data->mtx_print_status, &ft_print_status);
		philo->data->died = 1;
		return (1);
	}
	return (0);
}

int8_t continue_monitor(t_philo *philo)
{
	int8_t alive;

	alive = !do_mtx(philo, &philo->data->mtx_died, check_died);
	return (alive);
}

void *ft_monitor(void *arg)
{
	t_philo *philo;

	philo = arg;	
	while(continue_monitor(philo)) {
		if (usleep(500))
			return (NULL);
	}
	return (NULL);
}