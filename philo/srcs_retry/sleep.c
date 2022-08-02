#include "philosopher_retry.h"

int8_t ft_sleep(t_philo *philo)
{
	ft_print_status(philo, SLEEP);
	if(usleep(philo->data->action_time.time_sleep))
		return (ERROR);
	return (0);
}