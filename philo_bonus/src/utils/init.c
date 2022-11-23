#include "../../inc/philo.h"

static int  __init__sema(t_prog *prog)
{
    sem_unlink("/philo_forks");
    sem_unlink("/philo_write");
    sem_unlink("/philo_death");
    sem_unlink("/philo_stop");
    prog->forks = sem_open("/philo_forks", O_CREAT, 0600, prog->rules->nb_philo);
    prog->write = sem_open("/philo_write", O_CREAT, 0600, 1);
    prog->death = sem_open("/philo_death", O_CREAT, 0600, 1);
    prog->stop = sem_open("/philo_stop", O_CREAT, 0600, 1);
}

static void __init__philo(t_prog *prog)
{
    int i;

    i = 0;
    while (i < prog->rules->nb_philo)
    {
        prog->philo[i].id = i;
        prog->philo[i].ate = 0;
        prog->philo[i].last_meal = 0;
        prog->philo[i].dead = 0;
        prog->philo[i].pid = -1;
        i++;
    }
}

static int __init__rules(t_rules *rules, char **argv)
{
	rules->died = 0;
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_death = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (rules->add_max_eat)
		rules->nb_eat = ft_atoi(argv[5]);
	else
		rules->nb_eat = 0;
    return (0);
}

int    __init__(t_prog *prog, char **argv, int max_eat)
{
    prog->writing = NULL;
    prog->forks = NULL;
    prog->stop = NULL;
	prog->death = NULL;
    prog->rules.add_max_eat = max_eat;
    prog->first_time = time_s();
    if (__init__rules(&prog->rules, argv))
        return (1);
    prog->philo = malloc(sizeof(t_prog) * prog->rules->nb_philo);
    return (0);
}