/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:47 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:30:31 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int64_t	philo_atoi(const char *str)
{
	int64_t	res;
	int8_t	negative;

	res = 0;
	negative = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' \
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	if (!ft_isdigitstr((char *)str))
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > (int64_t)INT_MIN * -1 && negative == -1)
			return (0);
	}
	return ((int64_t)res);
}

static int8_t	ft_init_arg(t_data *data, char **argv)
{
	data->num_philo = philo_atoi(argv[1]);
	data->action_time.time_die = philo_atoi(argv[2]);
	data->action_time.time_eat = philo_atoi(argv[3]);
	data->action_time.time_sleep = philo_atoi(argv[4]);
	data->at_least_eat_times = UNSET;
	data->at_least_eat_num_philo = UNSET;
	if (argv[5] != NULL)
	{
		data->at_least_eat_num_philo = data->num_philo;
		data->at_least_eat_times = philo_atoi(argv[5]);
		if (data->at_least_eat_times < 0)
			return (ft_error(E_INVALID_ARGUMENT));
	}
	if (data->num_philo < PHILO_MIN \
	|| data->num_philo > PHILO_MAX \
	|| data->action_time.time_die < TIME_DIE_MIN \
	|| data->action_time.time_eat < TIME_EAT_MIN \
	|| data->action_time.time_sleep < TIME_SLEEP_MIN)
		return (ft_error(E_INVALID_ARGUMENT));
	return (0);
}

static int8_t	ft_init_malloc(t_data *data, t_philo **philo)
{
	if (!(ft_malloc_p((void **)&data->th_philo, \
		sizeof(pthread_t) * data->num_philo))
		|| !(ft_malloc_p((void **)&data->th_monitor, \
		sizeof(pthread_t) * data->num_philo))
		|| !(ft_malloc_p((void **)&data->mtx_forks, \
		sizeof(pthread_mutex_t) * data->num_philo))
		|| !(ft_malloc_p((void **)&*philo, \
		sizeof(t_philo) * data->num_philo)))
		return (ft_error(E_MALLOCK));
	return (0);
}

static int8_t	ft_init_mutex(t_data *data)
{
	int32_t	i;

	if (pthread_mutex_init(&data->mtx_print_status, NULL) != 0
		|| pthread_mutex_init(&data->mtx_died, NULL) != 0)
		return (ft_error(E_MUTEX_INIT));
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_mutex_init(&data->mtx_forks[i], NULL) != 0)
			return (ft_error(E_MUTEX_INIT));
	}
	return (0);
}

int8_t	ft_init(t_data *data, t_philo **philo, char **argv)
{
	if (ft_init_arg(data, argv)
		|| ft_init_malloc(data, philo)
		|| ft_init_mutex(data))
		return (ERROR);
	return (0);
}
