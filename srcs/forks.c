#include "philosopher.h"

int	ft_take_forks(t_philo *philo)
{
	if (ft_m_lock(philo->right, &philo->info->status.died) == ERROR
		|| ft_output(philo, FORK) == ERROR)
		return (ERROR);
	if (ft_m_lock(philo->left, &philo->info->status.died) == ERROR
		|| ft_output(philo, FORK) == ERROR)
		return (ERROR);
	return (0);
}

int	ft_down_forks(t_philo *philo)
{
	if (ft_output(philo, SLEEP) == ERROR)
		return (ERROR);
	if (ft_m_unlock(philo->right, &philo->info->status.died) == ERROR
		|| ft_m_unlock(philo->left, &philo->info->status.died) == ERROR)
		return (ERROR);
	if (ft_action_usleep(philo->info->times.time_sleep, philo) == ERROR)
		return (ERROR);
	return (0);
}
