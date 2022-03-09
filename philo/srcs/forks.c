/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:55 by kyuki             #+#    #+#             */
/*   Updated: 2022/03/09 14:43:23 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_take_forks(t_philo *philo)
{
	if (ft_m_lock(philo->right, &philo->info->status.finish_m) == ERROR
		|| ft_output(philo, FORK) == ERROR)
		return (ERROR);
	if (philo->info->num_philo == 1)
	{
		ft_m_lock(philo->right, &philo->info->status.finish_m);
		return (0);
	}
	if (ft_m_lock(philo->left, &philo->info->status.finish_m) == ERROR
		|| ft_output(philo, FORK) == ERROR)
		return (ERROR);

	return (0);
}

int	ft_down_forks(t_philo *philo)
{
	if (ft_output(philo, SLEEP) == ERROR)
		return (ERROR);
	if (ft_m_unlock(philo->right, &philo->info->status.finish_m) == ERROR
		|| ft_m_unlock(philo->left, &philo->info->status.finish_m) == ERROR)
		return (ERROR);
	if (philo->info->status.died == FALSE)
	{
		if (ft_action_usleep(philo->info->times.time_sleep, philo) == ERROR)
			return (ERROR);
	}
	return (0);
}
