/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:15:54 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/24 00:54:38 by tgoel            ###   ########.fr       */
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
	writing_eating(philo, "is eating", philo->ate);
	philo->ate = philo->ate + 1;
	philo->last_meal = time_s();
	ft_usleep(prog->rules.time_eat * 1000);
	unlock_fork(prog);
	if (prog->rules.add_max_eat && philo->ate >= prog->rules.nb_eat)
	{
		philo->done_eating = 1;
		sem_post(prog->done);
		exit(0);
	}
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
