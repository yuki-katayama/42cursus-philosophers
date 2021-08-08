/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:48 by kyuki             #+#    #+#             */
/*   Updated: 2021/08/07 19:57:49 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_philo_is_died(t_philo *philo, long int elapsed_time)
{
	if ((!(philo->eating) && elapsed_time >= philo->info->times.time_die)
		|| (philo->info->status.limit_eats_mode
			&& philo->info->status.philos_limit_eats >= philo->info->num_philo)
		|| (philo->info->status.died == TRUE))
	{
		if (philo->info->status.died == FALSE)
			ft_output(philo, DEAD);
		return (1);
	}
	return (0);
}

void	*ft_monitor(void *p)
{
	t_philo		*philo;
	long int	elapsed_time;

	philo = p;
	while (1)
	{
		elapsed_time = ft_gettime(philo) - philo->time_last_eat;
		if (ft_philo_is_died(philo, elapsed_time))
			return (NULL);
		if (usleep(200) == -1)
		{
			pthread_mutex_unlock(&philo->info->status.finish_m);
			return ((void *)(size_t)ft_error(8));
		}
	}
	return (NULL);
}

int	ft_start_monitor(t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &ft_monitor, philo) != 0)
	{
		pthread_mutex_unlock(&philo->info->status.finish_m);
		return (ft_error(4));
	}
	if (pthread_detach(thread) != 0)
	{
		pthread_mutex_unlock(&philo->info->status.finish_m);
		return (ft_error(5));
	}
	return (0);
}
