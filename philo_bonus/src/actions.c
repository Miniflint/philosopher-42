/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:15:54 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/23 21:19:05 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	taking_fork(t_philo *philo)
{
	t_prog	*prog;

	prog = ft_get_prog(NULL);
	sem_wait(prog->forks);
	writing(philo, "Took a fork");
	sem_wait(prog->forks);
	writing(philo, "Took a fork");
}

void	unlock_fork(t_prog *prog)
{
	sem_post(prog->forks);
	sem_post(prog->forks);
}

void	eating(t_philo *philo)
{
	t_prog	*prog;

	prog = ft_get_prog(NULL);
	taking_fork(philo);
	writing(philo, "Is eating");
	philo->ate = philo->ate + 1;
	philo->last_meal = time_s();
	ft_usleep(prog->rules.time_eat * 1000);
	if (prog->rules.add_max_eat && philo->ate >= prog->rules.nb_eat)
	{
		printf("%d - Done eating\n", philo->id + 1);
		philo->done_eating = 1;
		unlock_fork(prog);
		exit(0);
	}
	unlock_fork(prog);
}

void	sleeping(t_philo *philo)
{
	t_prog	*prog;

	prog = ft_get_prog(NULL);
	writing(philo, "Is sleeping");
	ft_usleep(prog->rules.time_eat * 1000);
}

void	thinking(t_philo *philo)
{
	writing(philo, "Is thinking");
}
