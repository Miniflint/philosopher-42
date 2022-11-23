/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:57:27 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/23 22:08:54 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	lil_sem(t_prog *prog)
{
	sem_post(prog->death);
	sem_wait(prog->death);
}

void	*ft_check_death(void *arg)
{
	t_philo	*philo;
	t_prog	*prog;

	philo = (t_philo *)arg;
	prog = ft_get_prog(NULL);
	while (1)
	{
		sem_wait(prog->death);
		if (philo->last_meal && time_diff(philo->last_meal, time_s())
			> prog->rules.time_death)
		{
			writing(philo, "Is dead");
			sem_post(prog->stop);
			break ;
		}
		lil_sem(prog);
		if (prog->rules.add_max_eat && philo->ate >= prog->rules.nb_eat)
		{
			sem_post(prog->stop);
			break ;
		}
		sem_post(prog->death);
	}
	return (NULL);
}
