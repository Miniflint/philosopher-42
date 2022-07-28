#include "../../headers/philo.h"

int	sleeping(t_philo *philo)
{
	t_prog *prog;

	prog = philo->backup;
	if (prog->rules->died)
		return (1);
	if (writing(philo, "Is sleeping"))
		return (1);
	ft_usleep(prog->rules->time_sleep);
	return (0);
}
