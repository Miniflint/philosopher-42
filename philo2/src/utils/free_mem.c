#include "../../headers/philo.h"

void	free_mem(t_prog *prog)
{
	if (prog->rules)
		free(prog->rules);
	if (prog->philo)
		free (prog->philo);
}
