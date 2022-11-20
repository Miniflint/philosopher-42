/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 14:38:42 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	check_is_dead(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (philo->last_meal + prog->rules->time_die
		< (time_s() - prog->time_start))
	{
		if (writing(philo, "Is dead"))
			return (1);
		prog->rules->died = 1;
		return (1);
	}
	return (0);
}