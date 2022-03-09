/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:57:46 by kyuki             #+#    #+#             */
/*   Updated: 2022/03/09 15:02:11 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	ft_fill_nbr(char **output, long int time_last_eat)
{
	if (time_last_eat > 9)
		ft_fill_nbr(output, time_last_eat / 10);
	*(*output)++ = (time_last_eat % 10) + '0';
}

static void	ft_fill_status(char *output, char *status)
{
	int	i;
	int	len;

	len = ft_strlen(status);
	i = -1;
	while (++i < len)
		*(output++) = status[i];
}

static int	ft_output2(char *status, long int time_last_eat, int id)
{
	char	*output;
	char	*mem;
	int		len;

	len = ft_nbrlen(time_last_eat) + ft_nbrlen((long int)id) \
			+ (int)ft_strlen(status) + 2;
	if (!(ft_malloc_p((void **)&output, len)))
		return (ft_error(1));
	mem = output;
	ft_fill_nbr(&output, time_last_eat);
	*(output++) = ' ';
	ft_fill_nbr(&output, (long int)id);
	*(output++) = ' ';
	ft_fill_status(output, status);
	output = mem;
	write(STDOUT_FILENO, output, len);
	free(output);
	return (0);
}

int	ft_output(t_philo *philo, int serial)
{
	int	err;

	err = 0;
	pthread_mutex_lock(&philo->info->status.writing);
	if (philo->info->status.died == FALSE)
	{
		if (serial == FORK)
			err = ft_output2("has taken a fork\n", ft_gettime(philo), philo->id);
		else if (serial == EAT)
			err = ft_output2("is eating\n", philo->time_last_eat, philo->id);
		else if (serial == SLEEP)
			err = ft_output2("is sleeping\n", ft_gettime(philo), philo->id);
		else if (serial == THINK)
			err = ft_output2("is thinking\n", ft_gettime(philo), philo->id);
		else if (serial == DEAD)
		{
			if (!philo->eating && (ft_gettime(philo) - philo->time_last_eat) >= philo->info->times.time_die)
				err = ft_output2("died\n", ft_gettime(philo), philo->id);
			philo->info->status.died = TRUE;
			if (philo->info->num_philo == 1)
				ft_m_unlock(philo->right, &philo->info->status.finish_m);
		}
	}
	if ((err != 0) || (ft_m_unlock(&philo->info->status.writing, \
						&philo->info->status.finish_m) == ERROR))
		return (ERROR);
	return (0);
}
