#include "philosopher_retry.h"

int8_t ft_error(int32_t errno) {
	if (errno == E_INVALID_NUM_ARGUMENTS) {
		printf("Error: Invalid number of argumnets\n");
	} else if (errno == E_INVALID_ARGUMENT) {
		printf("Error: Invalid argument\n");
	} else if (errno == E_MALLOCK) {
		printf("Error: Failed to malloc\n");
	} else if (errno == E_MUTEX_INIT) {
		printf("Error: Can't work pthread_mutex_init\n");
	} else if (errno == E_GET_TIME_OF_DAY) {
		printf("Error: Can't work gettimeofday\n");
	} else if (errno == E_USLEEP) {
		printf("Error: Can't work usleep\n");

	}
	return (ERROR);
}