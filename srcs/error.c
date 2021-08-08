/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:58:00 by kyuki             #+#    #+#             */
/*   Updated: 2021/08/07 19:58:01 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_error(int errno)
{
	if (errno == 1)
		printf("Error: Failed to malloc\n");
	else if (errno == 2)
		printf("Error: Can't work pthread_mutex_init\n");
	else if (errno == 3)
		printf("Error: Invalid argument\n");
	else if (errno == 4)
		printf("Error: Can't work pthread_create\n");
	else if (errno == 5)
		printf("Error: Can't work pthread_detach\n");
	else if (errno == 6)
		printf("Error: Can't work pthread_mutex_lock\n");
	else if (errno == 7)
		printf("Error: Can't work pthread_mutex_unlock\n");
	else if (errno == 8)
		printf("Error: Can't work usleep\n");
	else if (errno == 9)
		printf("Error: Invalid number of argumnets\n");
	else if (errno == 10)
		printf("Error: Can't work gettimeofday\n");
	else if (errno == 11)
		printf("Error: Can't work pthread_mutex_destroy\n");
	return (ERROR);
}
