#include "../../headers/philo.h"

int	sleeping(t_philo *philo)
{
	t_prog *prog;

	prog = philo->backup;
	writing(philo, "Is sleeping");
	usleep(prog->rules->time_sleep * 1000);
	return (0);
}
