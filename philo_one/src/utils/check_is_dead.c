/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 16:57:22 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

int	check_all_deaths(t_prog *prog)
{
	int		i;

	while (!prog->rules->died)
	{
		i = -1;
		while (++i < prog->rules->nb_philo && !prog->rules->died)
		{
			if (time_diff(prog->philo[i].last_meal, time_s())
				> prog->rules->time_die)
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
