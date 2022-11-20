/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:01:57 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 15:36:30 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	thinking(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (check_is_dead(philo))
		return (1);
	if (prog->rules->died)
		return (1);
	if (philo->ate == prog->rules->nb_t_eat)
		return (0);
	if (writing(philo, "Is thinking"))
		return (1);
	return (0);
}
