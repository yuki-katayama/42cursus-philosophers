#include "philosopher_retry.h"

int8_t ft_init_forks(t_philo *philo) {
	philo->mtx_left = &philo->data->mtx_forks[(philo->id - 1)];
	philo->mtx_right = &philo->data->mtx_forks[(philo->id) % philo->data->num_philo];
	return (0);
}

void ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_left);
	do_mtx(&(t_print){philo, FORK}, &philo->data->mtx_print_status, &ft_print_status);
	pthread_mutex_lock(philo->mtx_right);
	do_mtx(&(t_print){philo, FORK}, &philo->data->mtx_print_status, &ft_print_status);
}

void ft_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->mtx_left);
	pthread_mutex_unlock(philo->mtx_right);
}