#include "../../headers/philo.h"

void	*routine(void *var)
{
	t_philo	*philo;
	t_prog	*prog;

	philo = (t_philo *)var;
	prog = (t_prog *)philo->backup;
	prog->rules->nb_t_eat = 12;
	if (philo->id % 2 == 0)
		eating(philo);
	else
		printf("philo %i\tis thinking\n", philo->id);
	return (0);
}