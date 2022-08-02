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

int8_t ft_usleep(int64_t time)
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
		if ((j - i) >= time) // || philo->data->status.died == TRUE 待っている時に誰かが死んだ時の処理
			break ;
		if (usleep(1000) == -1)
			return (ft_error(E_USLEEP));
	}
	return (0);
}