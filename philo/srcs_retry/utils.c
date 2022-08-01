#include "libft.h"
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
