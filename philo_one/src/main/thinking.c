/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:01:57 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/07 08:18:55 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	thinking(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (prog->rules->died)
		return (1);
	if (philo->ate == prog->rules->nb_t_eat)
		return (0);
	if (writing(philo, "Is thinking"))
		return (1);
	return (0);
}
