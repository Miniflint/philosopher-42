#include "../../headers/philo.h"

int	writing(t_philo *philo, char *str)
{
	t_prog		*prog;

	pthread_mutex_lock(philo->backup->writing);
	prog = philo->backup;
	if (prog->rules->died)
		return (1);
	printf("%lli \tphilo_%i\t %s\n", time_s() - prog->time_start, philo->id, str);
	pthread_mutex_unlock(philo->backup->writing);
	return (0);
}
