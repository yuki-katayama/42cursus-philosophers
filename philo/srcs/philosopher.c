/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:40 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:25:41 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_philosopher(void *arg)
{
	t_philo	*philo;

	philo = arg;
	ft_init_forks(philo);
	while (!is_died(philo))
	{
		ft_take_fork(philo);
		if (ft_eat(philo))
			break ;
		ft_down_fork(philo);
		ft_sleep(philo);
		do_mtx(philo, &philo->data->mtx_died, &print_think);
	}
	return (NULL);
}
