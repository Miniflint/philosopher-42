/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:57:27 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/24 00:50:45 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*check_all_done(void *arg)
{
	t_prog	*a;
	int		i;

	a = (t_prog *)arg;
	i = 0;
	while (i < a->rules.nb_philo)
	{
		sem_wait(a->done);
		i++;
	}
	sem_post(a->stop);
	a->all_done = 1;
	return (NULL);
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
			break ;
		}
		sem_post(prog->death);
	}
	sem_post(prog->stop);
	return (NULL);
}
