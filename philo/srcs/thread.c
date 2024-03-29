/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:34 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:25:35 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int8_t	ft_thread_create(t_data *data, t_philo *philo)
{
	int8_t	i;
	int64_t	j;

	i = -1;
	j = 0;
	while (++i != 2)
	{
		while (j < data->num_philo)
		{
			philo[j].id = j + 1;
			philo[j].data = data;
			philo[j].time_last_eat = UNSET;
			philo[j].can_max_eat_times = data->at_least_eat_times;
			if (pthread_create(&data->th_philo[j], NULL, \
				ft_philosopher, &philo[j])
				|| pthread_create(&data->th_monitor[j], NULL, \
				ft_monitor, &philo[j]))
				return (ft_error(E_PTHREAD_CREATE));
			j += 2;
		}
		usleep(1000);
		j = 1;
	}
	return (0);
}

int8_t	ft_thread_end(t_data *data, t_philo *philo)
{
	int32_t	i;

	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_join(data->th_philo[i], NULL)
			|| pthread_join(data->th_monitor[i], NULL))
			return (ft_error(E_PTHREAD_JOIN));
	}
	if (pthread_mutex_destroy(&data->mtx_print_status)
		|| pthread_mutex_destroy(&data->mtx_died))
		return (ft_error(E_PTHREAD_DESTROY));
	free(data->mtx_forks);
	free(data->th_philo);
	free(data->th_monitor);
	free(philo);
	return (0);
}
