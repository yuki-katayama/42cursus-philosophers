#include "philosopher.h"

long int	ft_gettime(t_philo *philo)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		pthread_mutex_unlock(&philo->info->died);
		return (ft_error(10));
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_action_usleep(long int time, t_philo *philo)
{
	long int	i;
	long int	j;

	i = ft_gettime(philo);
	if (i == ERROR)
		return (ERROR);
	while (1)
	{
		j = ft_gettime(philo);
		if (j == ERROR)
			return (ERROR);
		if ((j - i) >= time)
			break ;
		if (usleep(50) == -1)
			return (ft_error(8));
	}
	return (0);
}

int	ft_m_unlock(pthread_mutex_t *m, pthread_mutex_t *m_died)
{
	if (pthread_mutex_unlock(m) != 0)
	{
		pthread_mutex_unlock(m_died);
		return (ERROR);
	}
	return (0);
}

int	ft_m_lock(pthread_mutex_t *m, pthread_mutex_t *m_died)
{
	if (pthread_mutex_lock(m) != 0)
	{
		pthread_mutex_unlock(m_died);
		return (ERROR);
	}
	return (0);
}
