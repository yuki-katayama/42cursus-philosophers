/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:50 by kyuki             #+#    #+#             */
/*   Updated: 2021/08/08 21:39:20 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_philo_action_and_monitor(t_philo *philo)
{
	if (ft_start_monitor(philo))
		return (0);
	while (philo->info->status.died == FALSE)
	{
		if (ft_take_forks(philo) == ERROR
			|| ft_eat(philo) == ERROR
			|| ft_down_forks(philo) == ERROR
			|| ft_output(philo, THINK) == ERROR)
			return (ERROR);
	}
	return (0);
}

static void	*ft_philosopher(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
	{
		if (usleep(500) == -1)
		{
			pthread_mutex_unlock(&philo->info->status.finish_m);
			return ((void *)(size_t)ft_error(8));
		}
	}
	philo->time_last_eat = ft_gettime(philo);
	if (ft_philo_action_and_monitor(philo) == ERROR)
		return ((void *)(size_t)ERROR);
	pthread_mutex_lock(&philo->info->status.philos_died_m);
	philo->info->status.philos_died += 1;
	pthread_mutex_unlock(&philo->info->status.philos_died_m);
	if (philo->info->status.philos_died == philo->info->num_philo)
	{
		if (pthread_mutex_unlock(&philo->info->status.finish_m) != 0)
			ft_error(8);
	}
	return (NULL);
}

static int	ft_start(t_info *info)
{
	size_t	i;

	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_create(&info->threads[i], NULL, \
				ft_philosopher, (void *)&info->philo[i]))
			return (ft_error(4));
		if (pthread_detach(info->threads[i]))
			return (ft_error(5));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!(argc == 5 || argc == 6))
		return (ft_error(3));
	else if (ft_init(&info, argv) == ERROR)
		return (ERROR);
	if (ft_start(&info) == ERROR)
		return (ERROR);
	if (pthread_mutex_lock(&info.status.finish_m))
		return (ft_error(6));
	if (pthread_mutex_unlock(&info.status.finish_m))
		return (ft_error(7));
	ft_exit(&info);
	return (0);
}
