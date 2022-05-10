#include "philosopher.h"

int	ft_m_unlock(pthread_mutex_t *m, pthread_mutex_t *finish_m)
{
	if (pthread_mutex_unlock(m) != 0)
	{
		pthread_mutex_unlock(finish_m);
		return (ERROR);
	}
	return (0);
}

int	ft_m_lock(pthread_mutex_t *m, pthread_mutex_t *finish_m)
{
	if (pthread_mutex_lock(m) != 0)
	{
		pthread_mutex_unlock(finish_m);
		return (ERROR);
	}
	return (0);
}

void	do_mtx(void *arg, pthread_mutex_t *m, int (*func)())
{
	pthread_mutex_lock(m);
	func(arg);
	pthread_mutex_unlock(m);
}
