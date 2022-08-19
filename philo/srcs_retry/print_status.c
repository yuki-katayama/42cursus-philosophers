#include "philosopher_retry.h"

int8_t	ft_print_status(t_print *print_data)
{
	if (print_data->philo->data->died != 1)
	{
		if (print_data->status == FORK)
			printf("%s%ld %d has taken a fork%s\n", \
				GREEN, ft_gettime(), print_data->philo->id, DEFAULT);
		else if (print_data->status == EAT)
			printf("%s%ld %d is eating%s\n", \
				YELLOW, ft_gettime(), print_data->philo->id, DEFAULT);
		else if (print_data->status == SLEEP)
			printf("%s%ld %d is sleeping%s\n", \
				BLUE, ft_gettime(), print_data->philo->id, DEFAULT);
		else if (print_data->status == THINK)
			printf("%ld %d is thinking\n", \
				ft_gettime(), print_data->philo->id);
		else if (print_data->status == DIED)
		{
			printf("%s%ld %d died%s\n", \
				RED, ft_gettime(), print_data->philo->id, DEFAULT);
		}
	}
	return (0);
}
