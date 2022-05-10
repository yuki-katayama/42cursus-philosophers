/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:39 by kyuki             #+#    #+#             */
/*   Updated: 2022/05/10 21:44:25 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int ft_usleep(useconds_t usec, pthread_mutex_t *m) {
	if (usleep(usec) == -1)
	{
		pthread_mutex_unlock(m);
		return (ft_error(E_USLEEP));
	}
	return (0);
}

int after_dead(t_info *info) {
	info->status.philos_died += 1;
	if (info->status.philos_died == info->num_philo)
	{
		if (pthread_mutex_unlock(&info->status.finish_m) != 0)
			return (ft_error(E_MUTEX_UNLOCK));
	}
	return (0);
}

void do_mtx(void *arg, pthread_mutex_t *m, int (*func)())
{
	pthread_mutex_lock(m);
	func(arg);
	pthread_mutex_unlock(m);
}

long int	ft_gettime(t_philo *philo)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		pthread_mutex_unlock(&philo->info->status.finish_m);
		return (ft_error(E_GET_TIME_OF_DAY));
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
		if ((j - i) >= time || philo->info->status.died == TRUE)
			break ;
		if (usleep(1000) == -1)
			return (ft_error(E_USLEEP));
	}
	return (0);
}

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
