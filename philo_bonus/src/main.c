#include "../inc/philo.h"
#include <stdio.h>

void    routine(t_philo *philo)
{
//    if (philo->id % 2 == 0)
//        ft_usleep(400);
    writing(philo, "Se lance doucement mais surement hehehehehehe");
    while (1)
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
        //break ;
    }
	exit(0);
}

int create_proc(t_prog *prog)
{
    int i;

    i = 0;
    while (i < prog->rules.nb_philo)
    {
        prog->philo[i].pid = fork();
        if (prog->philo[i].pid == 0)
			routine(&(prog->philo[i]));
        ft_usleep(50);
        i++;
    }
    return (0);
}

int create_prog(t_prog *prog)
{
    __init__sema(prog);
    sem_wait(prog->stop);
    create_proc(prog);
    //sem_wait(prog->stop);
    return (0);
}


int main(int argc, char **argv)
{
    t_prog  prog;

    ft_get_prog(&prog);
    if (argc == 5)
        __init__(&prog, argv, 0);
    else if (argc == 6)
        __init__(&prog, argv, ft_atoi(argv[5]));
    else
    {
        write(2, "Not enough args\n", 16);
        return (1);
    }
    create_prog(&prog);
	destroy_all(&prog);
    return (0);
}