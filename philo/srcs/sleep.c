/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:36 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:26:51 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int8_t	ft_sleep(t_philo *philo)
{
	do_mtx(philo, &philo->data->mtx_died, &print_sleep);
	if (ft_usleep(philo->data->action_time.time_sleep, philo))
		return (ERROR);
	return (0);
}
