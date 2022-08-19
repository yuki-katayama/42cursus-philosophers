#include "philosopher.h"
static int8_t is_expired_time(t_philo *philo)
{
	int64_t elapsed_time;

	elapsed_time = ft_gettime() - philo->time_last_eat;
	return (philo->time_last_eat != UNSET && elapsed_time >= philo->data->action_time.time_die);
}

static int8_t is_expired_eat_times(t_philo *philo)
{
	if(philo->can_max_eat_times == 0 && philo->can_max_eat_times != UNSET) {
		philo->data->at_least_eat_num_philo -= 1;
		philo->can_max_eat_times -= 1;
		if (philo->data->at_least_eat_num_philo == 0) {
			return (1);
		}
	}
	return (0);
}

static int8_t check_died(t_philo *philo)
{
	if(is_expired_time(philo) || philo->data->died == 1 || is_expired_eat_times(philo) || philo->data->num_philo == 1) {
		if (philo->data->at_least_eat_num_philo != 0)
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