#include "philosopher.h"

static int8_t ft_update_after_eat(t_philo *philo)
{
	philo->time_last_eat = ft_gettime();
	if (philo->can_max_eat_times != UNSET)
		philo->can_max_eat_times -= 1;
	return (0);
}

int8_t ft_eat(t_philo *philo)
{
	do_mtx(philo, &philo->data->mtx_died, &ft_update_after_eat);
	do_mtx(&(t_print){philo, EAT}, &philo->data->mtx_print_status, &ft_print_status);
	if (ft_usleep(philo->data->action_time.time_eat, philo) == ERROR) {
		return (ERROR);
	}
	return (0);
}