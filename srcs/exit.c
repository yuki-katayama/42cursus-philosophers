#include "philosopher.h"

void	ft_exit(t_info *info)
{
	// size_t	i;
	// int err;

	// i = -1;
	// while (++i < info->num_philo)
	// {
	// }
	// if (pthread_mutex_destroy(&info->writing))
	// {
	// 	printf("%db\n", err);
	// 	ft_error(11);
	// }
	// if ((pthread_mutex_destroy(info->philo[0].left) != 0)
	// 	|| (pthread_mutex_destroy(info->philo[0].right)) != 0)
	// 	{
	// 		// printf("%da\n", err);
	// 		ft_error(11);
	// 	}
	if (pthread_mutex_destroy(&info->died))
	{
		// printf("%dc\n", err);
		ft_error(11);
	}
	free(info->forks);
	free(info->threads);
	free(info->philo);
}