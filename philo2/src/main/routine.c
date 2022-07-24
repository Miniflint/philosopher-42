#include "../../headers/philo.h"

void	*routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	printf("test from thread: %i\n", philo->id);
	return (0);
}
