/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:46:58 by kyuki             #+#    #+#             */
/*   Updated: 2022/05/09 01:31:42 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int ft_eat_action(t_philo *philo) {
	philo->eating = 1;
	philo->time_last_eat = ft_gettime(philo);
	if (ft_output(philo, EAT) == ERROR)
		return (ERROR);
	if (ft_action_usleep(philo->info->times.time_eat, philo) == ERROR)
		return (ERROR);
	return 0;
}

int	ft_eat(t_philo *philo)
{
	if (philo->info->status.died == FALSE)
	{
		ft_eat_action(philo);
		philo->limit_eats -= 1;
		if (philo->limit_eats == 0)
			philo->info->status.philos_limit_eats += 1;
		philo->eating = 0;
	}
	return (0);
}
