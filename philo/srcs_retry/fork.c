#include "philosopher_retry.h"

void ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	ft_print_status(philo, FORK);
	pthread_mutex_lock(philo->right);
	ft_print_status(philo, FORK);
}

void ft_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}