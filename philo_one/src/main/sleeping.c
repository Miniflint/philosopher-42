/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:01:36 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 18:13:47 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	sleeping(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (philo->done_eating)
		return (2);
	if (philo->ate == prog->rules->nb_t_eat)
		return (0);
	if (writing(philo, P_SLEEP))
		return (1);
	ft_usleep(prog->rules->time_sleep);
	return (0);
}
