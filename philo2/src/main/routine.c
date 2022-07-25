#include "../../headers/philo.h"

void	*routine(void *var)
{
	int	i;
	t_philo	*philo;
	t_prog	*prog;

	philo = (t_philo *)var;
	prog = (t_prog *)philo->backup;
	prog->rules->nb_t_eat = 12;
	i = prog->rules->nb_t_eat;
	while (i)
	{
		if (philo->id % 2 == 0)	
			eating(philo);
		thinking(philo);
		i--;
	}
	return (0);
}
