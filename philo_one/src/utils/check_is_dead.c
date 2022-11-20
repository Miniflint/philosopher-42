/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 18:28:53 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	actualise_ate_done(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (prog->rules->add_max_eat && philo->ate >= prog->rules->nb_t_eat)
	{
		philo->last_meal= time_s();
	}
}

int	check_all_eat(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->rules->nb_philo)
	{
		if (!prog->philo[i].done_eating)
			return (0);
		i++;
	}
	return (1);
}

int	check_all_deaths(t_prog *prog)
{
	int		i;

	while (1)
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
			if (check_all_eat(prog))
				return (0) ;
			actualise_ate_done(&(prog->philo[i]));
			usleep(200);
		}
		if (prog->rules->died)
			break ;
	}
	return (0);
}
