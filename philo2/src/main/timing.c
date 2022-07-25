#include "../../headers/philo.h"

int	actualize_time(t_prog *prog)
{
	int	c_check;

	c_check = gettimeofday(prog->value_time, NULL);
	if (c_check)
		return (1);
	return (prog->value_time->tv_usec - prog->time_start);
}


int	timing(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	prog->time_now = actualize_time(prog);
	return (0);
}
