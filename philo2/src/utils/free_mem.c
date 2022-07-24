#include "../../headers/philo.h"

void	free_mem(t_prog *prog)
{
	if (prog->rules)
		free(prog->rules);
	if (prog->philo)
		free (prog->philo);
	if (prog->threads)
		free(prog->threads);
	if (prog->value_time)
		free(prog->value_time);
}
