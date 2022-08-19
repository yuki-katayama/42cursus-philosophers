#include "philosopher.h"

int8_t ft_sleep(t_philo *philo)
{
	do_mtx(&(t_print){philo, SLEEP}, &philo->data->mtx_print_status, &ft_print_status);
	if(ft_usleep(philo->data->action_time.time_sleep, philo))
		return (ERROR);
	return (0);
}