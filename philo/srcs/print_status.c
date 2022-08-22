/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:38 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:25:40 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int8_t	print_eat(t_philo *philo)
{
	do_mtx(&(t_print){philo, EAT}, &philo->data->mtx_print_status, \
		&ft_print_status);
	return (0);
}

int8_t	print_fork(t_philo *philo)
{
	do_mtx(&(t_print){philo, FORK}, &philo->data->mtx_print_status, \
		&ft_print_status);
	return (0);
}

int8_t	print_sleep(t_philo *philo)
{
	do_mtx(&(t_print){philo, SLEEP}, &philo->data->mtx_print_status, \
		&ft_print_status);
	return (0);
}

int8_t	print_think(t_philo *philo)
{
	do_mtx(&(t_print){philo, THINK}, &philo->data->mtx_print_status, \
		&ft_print_status);
	return (0);
}

int8_t	ft_print_status(t_print *print_data)
{
	if (print_data->philo->data->died != 1)
	{
		if (print_data->status == FORK)
			printf("%s%lld %d has taken a fork%s\n", \
				GREEN, ft_gettime(), print_data->philo->id, DEFAULT);
		else if (print_data->status == EAT)
			printf("%s%lld %d is eating%s\n", \
				YELLOW, ft_gettime(), print_data->philo->id, DEFAULT);
		else if (print_data->status == SLEEP)
			printf("%s%lld %d is sleeping%s\n", \
				BLUE, ft_gettime(), print_data->philo->id, DEFAULT);
		else if (print_data->status == THINK)
			printf("%lld %d is thinking\n", \
				ft_gettime(), print_data->philo->id);
		else if (print_data->status == DIED)
		{
			printf("%s%lld %d died%s\n", \
				RED, ft_gettime(), print_data->philo->id, DEFAULT);
		}
	}
	return (0);
}
