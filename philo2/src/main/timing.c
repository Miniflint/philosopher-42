#include "../../headers/philo.h"

long long	time_s(void)
{
	int		i;
	struct timeval	t;

	i = gettimeofday(&t, NULL);
	if (i)
		return (-1);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	actualize_time(t_prog *prog)
{
	prog->time_now = time_s();
	if (prog->time_now == -1)
		return (1);
	return (0);
}
