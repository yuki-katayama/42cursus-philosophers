#include "philosopher_retry.h"

void *ft_philosopher(void *arg)
{
	t_philo *philo;

	(void)arg;

	philo = arg;
	philo->time_last_eat = -1;
	ft_init_forks(philo);
	while(is_alive(philo)) {
		ft_take_fork(philo);
		ft_eat(philo);
		ft_down_fork(philo);
		ft_sleep(philo);
		ft_print_status(philo, THINK);
	}
	return (NULL);
}