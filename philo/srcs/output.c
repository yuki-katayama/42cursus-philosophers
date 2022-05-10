/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:46 by kyuki             #+#    #+#             */
/*   Updated: 2022/05/10 23:16:26 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_print_status(t_philo *philo, int serial)
{
	if (serial == FORK)
		printf("%s%ld %d has taken a fork%s\n", \
			GREEN, ft_gettime(philo), philo->id, DEFAULT);
	else if (serial == EAT)
		printf("%s%ld %d is eating%s\n", \
			YELLOW, ft_gettime(philo), philo->id, DEFAULT);
	else if (serial == SLEEP)
		printf("%s%ld %d is sleeping%s\n", \
			BLUE, ft_gettime(philo), philo->id, DEFAULT);
	else if (serial == THINK)
		printf("%ld %d is thinking\n", \
			ft_gettime(philo), philo->id);
	else if (serial == DEAD)
	{
		if (!philo->eating && ft_gettime(philo) - philo->time_last_eat \
		>= philo->info->times.time_die)
			printf("%s%ld %d died%s\n", \
				RED, ft_gettime(philo), philo->id, DEFAULT);
		philo->info->status.died = TRUE;
		if (philo->info->num_philo == 1)
			ft_m_unlock(philo->right, &philo->info->status.finish_m);
	}
}

int	ft_output(t_philo *philo, int serial)
{
	int	err;

	err = 0;
	pthread_mutex_lock(&philo->info->status.writing);
	if (philo->info->status.died == FALSE)
		ft_print_status(philo, serial);
	if ((err != 0) || (ft_m_unlock(&philo->info->status.writing, \
						&philo->info->status.finish_m) == ERROR))
		return (ERROR);
	return (0);
}
