/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:53 by kyuki             #+#    #+#             */
/*   Updated: 2021/08/07 19:57:54 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_init_philos(t_info *info, int limit_eats)
{
	size_t			i;
	pthread_mutex_t	eating_m;

	i = -1;
	if (!(ft_malloc_p((void **)&info->philo, sizeof(t_philo) * info->num_philo))
		|| !(ft_malloc_p((void **)&info->threads, \
							sizeof(pthread_t) * info->num_philo))
		|| !(ft_malloc_p((void **)&info->forks, \
							sizeof(pthread_mutex_t) * info->num_philo)))
		return (ft_error(1));
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0
			|| pthread_mutex_init(&eating_m, NULL) != 0)
			return (ft_error(2));
		info->philo[i].eating = FALSE;
		info->philo[i].id = i + 1;
		info->philo[i].left = &(info->forks[i]);
		info->philo[i].right = &(info->forks[(i + 1) % info->num_philo]);
		info->philo[i].info = info;
		info->philo[i].time_last_eat = 0;
		info->philo[i].limit_eats = limit_eats;
		info->philo[i].eating_m = &eating_m;
	}
	return (0);
}

static int	ft_init_info(t_info *info, char **argv, int limit_eats)
{
	*info = (t_info){};
	if (pthread_mutex_init(&info->status.finish_m, NULL) != 0
		|| pthread_mutex_init(&info->status.writing, NULL) != 0
		|| pthread_mutex_init(&info->status.philos_died_m, NULL) != 0)
		return (ft_error(2));
	if (pthread_mutex_lock(&info->status.finish_m))
		return (ft_error(6));
	info->status.limit_eats_mode = FALSE;
	info->status.died = FALSE;
	info->status.philos_limit_eats = 0;
	info->status.philos_died = 0;
	info->num_philo = ft_atoi(argv[1]);
	info->times.time_die = ft_atoi(argv[2]);
	info->times.time_eat = ft_atoi(argv[3]);
	info->times.time_sleep = ft_atoi(argv[4]);
	if ((info->num_philo < 1 \
		|| info->num_philo > 200) \
		|| info->times.time_die < 10 \
		|| info->times.time_eat < 50 \
		|| info->times.time_sleep < 50)
		return (ft_error(9));
	if (limit_eats)
		info->status.limit_eats_mode = TRUE;
	return (0);
}

int	ft_init(t_info *info, char **argv)
{
	int	limit_eats;

	if (argv[5] != NULL)
	{
		limit_eats = ft_atoi(argv[5]);
		if (limit_eats < 1)
			return (ft_error(3));
	}
	else
		limit_eats = 0;
	if (ft_init_info(info, argv, limit_eats) == 1)
		return (ERROR);
	if (ft_init_philos(info, limit_eats) == 1)
		return (ERROR);
	return (0);
}
