#include "philosopher.h"

static void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->time_last_eat = ft_gettime(philo);
	if (ft_start_monitor(philo))
		return (NULL);
	if (philo->id % 2 == 0)
	{
		if (usleep(500) == -1)
		{
			pthread_mutex_unlock(&philo->info->status.died_m);
			return ((void *)(size_t)ft_error(8));
		}
	}
	while (philo->info->status.died == FALSE)
	{
		if (ft_take_forks(philo) == ERROR
			|| ft_eat(philo) == ERROR
			|| ft_down_forks(philo) == ERROR
			|| ft_output(philo, THINK) == ERROR)
			return ((void *)(size_t)ERROR);
	}
	return (NULL);
}

static int	ft_start(t_info *info)
{
	size_t	i;

	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_create(&info->threads[i], NULL, \
				philosopher, (void *)&info->philo[i]))
			return (ft_error(4));
		if (pthread_detach(info->threads[i]))
			return (ft_error(5));
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_info	info;

	if (!(argc == 5 || argc == 6))
		return (ft_error(3));
	else if (ft_init(&info, argv) == ERROR)
		return (ERROR);
	if (ft_start(&info) == ERROR)
		return (ERROR);
	if (pthread_mutex_lock(&info.status.died_m))
		return (ft_error(6));
	if (pthread_mutex_unlock(&info.status.died_m))
		return (ft_error(7));
	ft_exit(&info);
	return (0);
}
