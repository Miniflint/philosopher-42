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
			if (eating(philo))
				return ((void *)1);
			if (sleeping(philo))
				return ((void *)1);
			if (thinking(philo))
				return ((void *)1);
		}
		else
		{
			if (!i)
				ft_usleep(100);
			if (thinking(philo))
				return ((void *)1);
			if (eating(philo))
				return ((void *)1);
			if (sleeping(philo))
				return ((void *)1);
		}
		i++;
	}
	if (prog->rules->died)
		return ((void *)1);
	return (0);
}
