#include "../../headers/philo.h"

int	thinking(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (prog->rules->died)
		return (1);
	if (writing(philo, "Is thinking"))
		return (1);
	return (0);
}
