/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:01:57 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/01 20:02:00 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	thinking(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (prog->rules->died)
		return (1);
	if (writing(philo, "Is thinking"))
		return (1);
	return (0);
}
