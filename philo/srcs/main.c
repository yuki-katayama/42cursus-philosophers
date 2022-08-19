#include "philosopher.h"

int main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	philo = NULL;
	data = &(t_data){};
	if (!(argc ==  5 || argc == 6))
		return (ft_error(E_INVALID_NUM_ARGUMENTS));
	if (ft_init(data, &philo, argv)
	|| ft_thread_create(data, philo)
	|| ft_thread_end(data, philo))
		return (ERROR);
}