#include "../../headers/philo.h"

void	*routine(void *var)
{
	int	i;
	t_philo	*philo;
	t_prog	*prog;

	philo = (t_philo *)var;
	prog = (t_prog *)philo->backup;
	i = 0;
	while (!prog->rules->died)
	{
		if (prog->rules->nb_t_eat)
			if (philo->ate >= prog->rules->nb_t_eat)
				break ;
		if (philo->id % 2 == 0)
		{	
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
		else
		{
			if (!i)
				usleep(500);
			thinking(philo);
			eating(philo);
			sleeping(philo);
		}
		i++;
	}
	return (0);
}
