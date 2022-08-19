#include "philosopher.h"

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
