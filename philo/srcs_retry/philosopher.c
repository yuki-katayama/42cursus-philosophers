#include "philosopher_retry.h"

void *ft_philosopher(void *arg)
{
	t_philo *philo;

	(void)arg;

	philo = arg;
	ft_init_forks(philo);
	while(continue_monitor(philo)) {
		ft_take_fork(philo);
		ft_eat(philo);
		ft_down_fork(philo);
		ft_sleep(philo);
		do_mtx(&(t_print){philo, THINK}, &philo->data->mtx_print_status, &ft_print_status);
	}
	return (NULL);
}
