/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:50 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:25:52 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int8_t	ft_init_forks(t_philo *philo)
{
	philo->mtx_left = &philo->data->mtx_forks[(philo->id - 1)];
	philo->mtx_right = \
		&philo->data->mtx_forks[(philo->id) % philo->data->num_philo];
	return (0);
}

int8_t	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_left);
	do_mtx(&(t_print){philo, FORK}, &philo->data->mtx_print_status, \
		&ft_print_status);
	if (philo->data->num_philo == 1)
	{
		pthread_mutex_unlock(philo->mtx_left);
		return (1);
	}
	do_mtx(&(t_print){philo, FORK}, &philo->data->mtx_print_status, \
		&ft_print_status);
	philo->have_right = 1;
	return (0);
}

void	ft_down_fork(t_philo *philo)
{
	if (philo->have_left == 1)
		pthread_mutex_unlock(philo->mtx_left);
	if (philo->have_right == 1)
		pthread_mutex_unlock(philo->mtx_right);
}
