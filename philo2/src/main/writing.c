#include "../../headers/philo.h"

int	writing(t_philo *philo, char *str)
{
	t_prog		*prog;

	prog = philo->backup;
	actualize_time(prog);
	pthread_mutex_lock(prog->writing);
	printf("%lli\tphilo_%i\t%s\n", time_s() - prog->time_start, philo->id, str);
	pthread_mutex_unlock(prog->writing);
	return (0);
}
