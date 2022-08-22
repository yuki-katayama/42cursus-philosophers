/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:55 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:26:46 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int8_t	ft_update_after_eat(t_philo *philo)
{
	philo->time_last_eat = ft_gettime();
	if (philo->can_max_eat_times != UNSET)
		philo->can_max_eat_times -= 1;
	return (0);
}

int8_t	ft_eat(t_philo *philo)
{
	do_mtx(philo, &philo->data->mtx_died, &ft_update_after_eat);
	do_mtx(philo, &philo->data->mtx_died, &print_eat);
	if (ft_usleep(philo->data->action_time.time_eat, philo) == ERROR)
	{
		return (ERROR);
	}
	return (0);
}
