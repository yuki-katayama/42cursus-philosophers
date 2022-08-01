#include "philosopher_retry.h"

enum	e_error {
	E_INVALID_NUM_ARGUMENTS = 1,
	E_INVALID_ARGUMENT,
	// E_MALLOCK,
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
	}
	return (ERROR);
}

int8_t ft_validate_arg(t_data *data) {
	if ((  data->num_philo < PHILO_MIN \
	|| data->num_philo > PHILO_MAX) \
	|| data->time_die < TIME_DIE_MIN \
	|| data->time_eat < TIME_EAT_MIN \
	|| data->time_sleep < TIME_SLEEP_MIN)
		return (ERROR);
	return (0);
}


void ft_init(t_data *data, char **argv) {
	data->num_philo = philo_atoi(argv[1]);
	data->time_die = philo_atoi(argv[2]);
	data->time_eat = philo_atoi(argv[3]);
	data->time_sleep = philo_atoi(argv[4]);
	data->limit_eats = -1;
	if (argv[5] != NULL)
		data->limit_eats = philo_atoi(argv[5]);
}

void ft_create_thread() {

}

void *ft_philo(void *arg)
{
	t_data *data;

	data = arg;
	printf("%ld %ld %ld %ld %ld\n", data->limit_eats, data->num_philo, data->time_die, data->time_eat, data->time_sleep);
	usleep(1000000);
	return (NULL);
}


int main(int argc, char **argv)
{
	t_data data;

	if (!(argc ==  5 || argc == 6)) {
		return (ft_error(E_INVALID_NUM_ARGUMENTS));
	}
	ft_init(&data, argv);
	if(ft_validate_arg(&data)) {
		return (ft_error(E_INVALID_ARGUMENT));
	}
	pthread_t a;
	pthread_create(&a, NULL, ft_philo, &data);
	pthread_join(a, NULL);
}