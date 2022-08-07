/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:56:22 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/07 08:19:08 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	while_if_loop(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{	
		if (eating(philo))
			return (1);
		if (sleeping(philo))
			return (1);
		if (thinking(philo))
			return (1);
	}
	else
	{
		if (sleeping(philo))
			return (1);
		if (thinking(philo))
			return (1);
		if (eating(philo))
			return (1);
	}
	return (0);
}

void	*routine(void *var)
{
	int		i;
	t_philo	*philo;
	t_prog	*prog;

	philo = (t_philo *)var;
	prog = (t_prog *)philo->backup;
	i = 0;
	while (!prog->rules->died)
	{
		if (prog->rules->nb_t_eat)
			if (philo->ate >= prog->rules->nb_t_eat)
				break ;
		if (while_if_loop(philo))
			break ;
		i++;
	}
	if (prog->rules->died)
		return ((void *)1);
	return (0);
}
