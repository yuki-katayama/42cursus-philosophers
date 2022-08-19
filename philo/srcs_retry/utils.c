#include "libft.h"
#include "philosopher_retry.h"

int64_t	philo_atoi(const char *str)
{
	int64_t	res;
	int8_t	negative;

	res = 0;
	negative = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' \
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+')
	{
		str++;
	}
	if (!ft_isdigitstr((char *)str))
	{
		return (-1);
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > (int64_t)INT_MIN * -1 && negative == -1)
			return (0);
	}
	return ((int64_t)res);
}

int64_t	ft_gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (ft_error(E_GET_TIME_OF_DAY));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int8_t ft_usleep(int64_t time, t_philo *philo)
{
	int64_t	i;
	int64_t	j;

	i = ft_gettime();
	if (i == ERROR)
		return (ERROR);
	while (1)
	{
		j = ft_gettime();
		if (j == ERROR)
			return (ERROR);
		if ((j - i) >= time || philo->data->died)
			break ;
		if (usleep(200) == -1)
			return (ft_error(E_USLEEP));
	}
	return (0);
}

int8_t	do_mtx(void *arg, pthread_mutex_t *m, int8_t (*func)())
{
	int8_t ret;

	pthread_mutex_lock(m);
	ret = func(arg);
	pthread_mutex_unlock(m);
	return (ret);
}

static int8_t is_expired_time(t_philo *philo)
{
	int64_t elapsed_time;

	elapsed_time = ft_gettime() - philo->time_last_eat;
	return (philo->time_last_eat != -1 && elapsed_time >= philo->data->action_time.time_die);
}

static int8_t is_expired_eat_times(t_philo *philo)
{
	if(philo->can_max_eat_times == 0 && philo->can_max_eat_times != -1) {
		philo->data->at_least_eat_num_philo -= 1;
		philo->can_max_eat_times -= 1;
		if (philo->data->at_least_eat_num_philo == 0) {
			return (1);
		}
	}
	return (0);
}

int8_t is_died(t_philo *philo)
{
	return (is_expired_time(philo) || philo->data->died == 1 || is_expired_eat_times(philo));
}