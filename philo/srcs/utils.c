/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:29 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:30:14 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

int64_t	ft_gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (ft_error(E_GET_TIME_OF_DAY));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int8_t	ft_usleep(int64_t time, t_philo *philo)
{
	int64_t	i;
	int64_t	j;

	i = ft_gettime();
	if (i == ERROR)
		return (ERROR);
	while (1)
	{
		j = ft_gettime();
		if (j == ERROR)
			return (ERROR);
		if ((j - i) >= time || is_died(philo))
			break ;
		if (usleep(200) == -1)
			return (ft_error(E_USLEEP));
	}
	return (0);
}

int8_t	do_mtx(void *arg, pthread_mutex_t *m, int8_t (*func)())
{
	int8_t	ret;

	pthread_mutex_lock(m);
	ret = func(arg);
	pthread_mutex_unlock(m);
	return (ret);
}

static int8_t	return_died_var(t_philo *philo)
{
	return (philo->data->died);
}

int8_t	is_died(t_philo *philo)
{
	return (do_mtx(philo, &philo->data->mtx_died, &return_died_var));
}
