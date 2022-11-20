/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:01:36 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 16:55:32 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	sleeping(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (prog->rules->died)
		return (1);
	if (philo->ate == prog->rules->nb_t_eat)
		return (0);
	if (writing(philo, P_SLEEP))
		return (1);
	ft_usleep(prog->rules->time_sleep);
	if (prog->rules->died)
		return (1);
	return (0);
}
