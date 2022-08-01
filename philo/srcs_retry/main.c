#include "philosopher_retry.h"

enum	e_error {
	E_INVALID_NUM_ARGUMENTS = 1,
	E_INVALID_ARGUMENT,
	E_MALLOCK,
	// E_MUTEX_INIT,
	// E_PTHREAD_CREATE,
	// E_PTHREAD_DETACH,
	// E_MUTEX_LOCK,
	// E_MUTEX_UNLOCK,
	// E_USLEEP,
	// E_GET_TIME_OF_DAY,
};

int8_t ft_error(int32_t errno) {
	if (errno == E_INVALID_NUM_ARGUMENTS) {
		printf("Error: Invalid number of argumnets\n");
	} else if (errno == E_INVALID_ARGUMENT) {
		printf("Error: Invalid argument\n");
	} else if (errno == E_MALLOCK)
		printf("Error: Failed to malloc\n");
	return (ERROR);
}

int8_t ft_validate_arg(t_data *data) {
	if ((  data->num_philo < PHILO_MIN \
	|| data->num_philo > PHILO_MAX) \
	|| data->time_die < TIME_DIE_MIN \
	|| data->time_eat < TIME_EAT_MIN \
	|| data->time_sleep < TIME_SLEEP_MIN)
		return (ft_error(E_INVALID_ARGUMENT));
	return (0);
}


int8_t ft_init(t_data *data, char **argv) {
	data->num_philo = philo_atoi(argv[1]);
	data->time_die = philo_atoi(argv[2]);
	data->time_eat = philo_atoi(argv[3]);
	data->time_sleep = philo_atoi(argv[4]);
	data->limit_eats = -1;
	if (argv[5] != NULL)
		data->limit_eats = philo_atoi(argv[5]);
	if (!(ft_malloc_p((void **)&data->th_philo, sizeof(pthread_t) * data->num_philo))
		|| !(ft_malloc_p((void **)&data->th_monitor, sizeof(pthread_t) * data->num_philo)))
		return (ft_error(E_MALLOCK));
	return (0);
}

int64_t ft_init_philo(t_data *data, t_philo **philo)
{
	// printf("%ld\n", sizeof(t_philo) * data->num_philo);
	// // if (!(ft_malloc_p((void **)&*philo, sizeof(t_philo) * data->num_philo)))
	// // 	return (ft_error(E_MALLOCK));
	*philo = malloc(sizeof(t_philo) * (data->num_philo + 1));
	// int i = 0;
	// while(i < data->num_philo)
	// {
	// 	printf("%ld, %d\n", data->num_philo, i);
	// 	(*philo[i]).id = i;
	// 	// philo[i]->data = data;
	// 	// *philo[i]++;
	// 	i++;
	// }
	// // philo[0]->id = 1;

	t_philo *philo1;
	philo1 = malloc(sizeof(t_philo) * (data->num_philo + 1));
	int i = 0;
	while(i < data->num_philo)
	{
		printf("%ld, %d\n", data->num_philo, i);
		philo1[i].id = i;
		// philo[i]->data = &*data;
		// *philo[i]++;
		i++;
	}
	free(philo1);
	return (0);
}

void ft_create_thread() {

}

void *ft_philo(void *arg)
{
	// t_philo *philo;

	(void)arg;

	// philo = arg;
	// printf("%ld: %ld %ld %ld %ld %ld\n", philo->id, philo->data->num_philo, philo->data->time_die, philo->data->time_eat, philo->data->time_sleep, philo->data->limit_eats);
	usleep(100000);
	return (NULL);
}


int main(int argc, char **argv)
{
	t_data *data;
	t_philo *philo;

	philo = NULL;
	data = &(t_data){};
	if (!(argc ==  5 || argc == 6)) {
		return (ft_error(E_INVALID_NUM_ARGUMENTS));
	}
	if (ft_init(data, argv)
	|| ft_validate_arg(data)
	||	ft_init_philo(data, &philo))
		return (ERROR);

	int64_t i = -1;
	while(++i < data->num_philo) {
		pthread_create(&data->th_philo[i], NULL, ft_philo, philo);
		pthread_join(data->th_philo[i], NULL);
	}
	free(data->th_philo);
	free(data->th_monitor);
	free(philo);
}