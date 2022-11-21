#ifndef PHILOSTRUCT_H
# define PHILOSTRUCT_H

# include "philo.h"

typedef struct S_philo
{
	int		id;
	int		ate;
	long long	last_meal;
	sem_t		fork_right;
	sem_t		*fork_left;
}	t_philo;

typedef struct S_rules
{
	int	nb_philo;
	int	time_death;
	int	time_eat;
	int	time_sleep;
	int	nb_eat;
	int	died;
	int	add_max_eat;
}	t_rules;

typedef struct S_prog
{
	
	long long	first_time;
	t_rules		rules;
	sem_t		*writing;
	t_philo		*philo;
}	t_prog;


#endif
