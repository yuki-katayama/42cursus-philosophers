#include "philosopher.h"

void	ft_exit(t_info *info)
{
	free(info->forks);
	free(info->threads);
	free(info->philo);
}
