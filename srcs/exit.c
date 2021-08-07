#include "philosopher.h"

void ft_exit(t_info *info)
{
	size_t i;
	int err;

	i = -1;
	err = 0;
	while (++i < info->num_philo)
	{
		if (pthread_mutex_unlock(&info->forks[i]) != 0)
		{
			printf("%da\n", err);
			ft_error(11);
		}
		if (pthread_mutex_destroy(&info->forks[i]) != 0)
		{
			printf("%da\n", err);
			ft_error(11);
		}
	}
	if (pthread_mutex_destroy(&info->status.died_m) != 0 || pthread_mutex_destroy(&info->status.writing) != 0)
	{
		printf("%dc\n", err);
		ft_error(11);
	}
	free(info->forks);
	free(info->threads);
	free(info->philo);
}