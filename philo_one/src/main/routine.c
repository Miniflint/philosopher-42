/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:56:22 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 18:13:18 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	*routine(void *var)
{
	int		i;
	t_philo	*philo;
	t_prog	*prog;

	philo = (t_philo *)var;
	prog = (t_prog *)philo->backup;
	i = 0;
	if (philo->id % 2 == 0)
		ft_usleep(1500);
	while (!prog->rules->died)
	{
		if (eating(philo) == 2)
			return (0);
		if (sleeping(philo) == 2)
			return (0);
		if (thinking(philo) == 2)
			return (0);
		i++;
	}
	return (0);
}
