#include "../../headers/philo.h"

void	*routine(void *var)
{
	t_philo	*philo;
	t_prog	*prog;

	philo = (t_philo *)var;
	prog = (t_prog *)philo->backup;
	prog->rules->nb_t_eat = 12;
	printf("entering: philo: %i\n", philo->id);
	usleep(2000000);
	printf("exiting: philo: %i\n", philo->id);
	return (0);
}
