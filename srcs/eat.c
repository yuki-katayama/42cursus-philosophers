#include "philosopher.h"

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->info->philo[(philo->id + 1) \
						% philo->info->num_philo].eating_m);
	pthread_mutex_lock(philo->info->philo[(philo->id - 1) \
						% philo->info->num_philo].eating_m);
	philo->eating = 1;
	philo->time_last_eat = ft_gettime(philo);
	if (ft_output(philo, EAT) == ERROR)
		return (ERROR);
	if (ft_action_usleep(philo->info->times.time_eat, philo) == ERROR)
		return (ERROR);
	pthread_mutex_unlock(philo->info->philo[(philo->id - 1) \
						% philo->info->num_philo].eating_m);
	pthread_mutex_unlock(philo->info->philo[(philo->id + 1) \
						% philo->info->num_philo].eating_m);
	philo->limit_eats -= 1;
	if (philo->limit_eats == 0)
		philo->info->status.philos_limit_eats += 1;
	philo->eating = 0;
	return (0);
}
