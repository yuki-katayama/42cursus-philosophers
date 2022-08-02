#include "philosopher_retry.h"

void	ft_print_status(t_philo *philo, int8_t action)
{
	if (action == FORK)
		printf("%s%ld %d has taken a fork%s\n", \
			GREEN, ft_gettime(), philo->id, DEFAULT);
	else if (action == EAT)
		printf("%s%ld %d is eating%s\n", \
			YELLOW, ft_gettime(), philo->id, DEFAULT);
	else if (action == SLEEP)
		printf("%s%ld %d is sleeping%s\n", \
			BLUE, ft_gettime(), philo->id, DEFAULT);
	else if (action == THINK)
		printf("%ld %d is thinking\n", \
			ft_gettime(), philo->id);
}