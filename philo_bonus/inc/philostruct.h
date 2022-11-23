#ifndef PHILOSTRUCT_H
# define PHILOSTRUCT_H

# include "philo.h"

typedef struct S_philo
{
	int			id;
	int			ate;
	int			dead;
	long long	last_meal;
	pid_t		pid;
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
	t_philo		*philo;
	pthread_t	death_check;
	sem_t		*write;
	sem_t		*forks;
	sem_t		*stop;
	sem_t		*death;
}	t_prog;


#endif