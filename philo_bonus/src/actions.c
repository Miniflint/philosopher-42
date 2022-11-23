#include "../inc/philo.h"

void	taking_fork(t_philo *philo)
{
    t_prog  *prog;

    prog = ft_get_prog(NULL);
	sem_wait(prog->forks);
	writing(philo, "Took a fork");
	sem_wait(prog->forks);
	writing(philo, "Took a fork");
}

void    unlock_fork(t_prog *prog)
{
	sem_post(prog->forks);
	sem_post(prog->forks);
}

void	eating(t_philo *philo)
{
    t_prog  *prog;

    prog = ft_get_prog(NULL);
    taking_fork(philo);
	writing(philo, "Is eating");
    philo->ate = philo->ate + 1;
	ft_usleep(prog->rules.time_eat * 1000);
	philo->last_meal = time_s();
}

void	sleeping(t_philo *philo)
{
    t_prog  *prog;

    prog = ft_get_prog(NULL);
	writing(philo, "Is sleeping");
	ft_usleep(prog->rules.time_eat * 1000);
}

void    thinking(t_philo *philo)
{
    writing(philo, "Is thinking");
}