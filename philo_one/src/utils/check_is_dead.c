/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 16:48:02 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

int	check_is_dead(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (!philo->last_meal)
		return (0);
	if (time_diff(philo->last_meal, time_s()) > prog->rules->time_die)
	{

		return (1);
	}
	return (0);
}

int	check_all_deaths(t_prog *prog)
{
	int		i;

	printf("Entering in the checking section\n");
	while (!prog->rules->died)
	{
		i = -1;
		while (++i < prog->rules->nb_philo && !prog->rules->died)
		{
			if (time_diff(prog->philo[i].last_meal, time_s()) > prog->rules->time_die)
			{
				if (writing(&(prog->philo[i]), "Is dead"))
					return (1);
				prog->rules->died = 1;
			}
			usleep(20);
		}
		if (prog->rules->died)
			break ;
	}
	return (0);
}