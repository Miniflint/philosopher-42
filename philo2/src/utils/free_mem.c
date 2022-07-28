#include "../../headers/philo.h"

// malloced: (in __init__)
//	rules: O
//	philo: O

// malloced: (in __init__philo)
//	writing: O
//	mutex: N

// malloced: (in __init__time)
//	value_time: O

void	free_all_mutex(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->rules->nb_philo)
	{
		pthread_mutex_destroy(&(prog->philo[i].fork_right_id));
		i++;
	}
	pthread_mutex_destroy(prog->writing);
}

void	free_mem(t_prog *prog)
{
	free_all_mutex(prog);
	if (prog->writing)
		free(prog->writing);
	if (prog->rules)
		free(prog->rules);
	if (prog->philo)
		free (prog->philo);
	if (prog->threads)
		free(prog->threads);
	if (prog->value_time)
		free(prog->value_time);
}
