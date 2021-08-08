/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:46:58 by kyuki             #+#    #+#             */
/*   Updated: 2021/08/08 21:46:59 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_eat(t_philo *philo)
{
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;

	right = philo->info->philo[(philo->id + 1) % \
								philo->info->num_philo].eating_m;
	left = philo->info->philo[(philo->id - 1) % \
								philo->info->num_philo].eating_m;
	if (philo->info->status.died == FALSE)
	{
		pthread_mutex_lock(right);
		pthread_mutex_lock(left);
		philo->eating = 1;
		philo->time_last_eat = ft_gettime(philo);
		if (ft_output(philo, EAT) == ERROR)
			return (ERROR);
		if (ft_action_usleep(philo->info->times.time_eat, philo) == ERROR)
			return (ERROR);
		pthread_mutex_unlock(left);
		pthread_mutex_unlock(right);
		philo->limit_eats -= 1;
		if (philo->limit_eats == 0)
			philo->info->status.philos_limit_eats += 1;
		philo->eating = 0;
	}
	return (0);
}
