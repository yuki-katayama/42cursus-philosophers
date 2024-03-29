/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:25:52 by kyuki             #+#    #+#             */
/*   Updated: 2022/08/20 04:25:55 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int8_t	ft_error(int32_t errno)
{
	if (errno == E_INVALID_NUM_ARGUMENTS)
		printf("Error: Invalid number of argumnets\n");
	else if (errno == E_INVALID_ARGUMENT)
		printf("Error: Invalid argument\n");
	else if (errno == E_MALLOCK)
		printf("Error: Failed to malloc\n");
	else if (errno == E_MUTEX_INIT)
		printf("Error: Can't work pthread_mutex_init\n");
	else if (errno == E_GET_TIME_OF_DAY)
		printf("Error: Can't work gettimeofday\n");
	else if (errno == E_USLEEP)
		printf("Error: Can't work usleep\n");
	else if (errno == E_PTHREAD_CREATE)
		printf("Error: Can't work pthread_create\n");
	else if (errno == E_PTHREAD_JOIN)
		printf("Error: Can't work pthread_join\n");
	else if (errno == E_PTHREAD_DESTROY)
		printf("Error: Can't work pthread_mutx_destroy\n");
	return (ERROR);
}
