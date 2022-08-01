/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:02:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/01 20:09:54 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	writing(t_philo *philo, char *str)
{
	t_prog		*prog;

	pthread_mutex_lock(philo->backup->writing);
	prog = philo->backup;
	if (prog->rules->died)
		return (1);
	if (philo->id >= 10)
		printf("%lli \tphilo_%i %s\n", time_s() - prog->time_start, philo->id, str);
	else
		printf("%lli \tphilo_%i\t %s\n", time_s() - prog->time_start, philo->id, str);
	pthread_mutex_unlock(philo->backup->writing);
	return (0);
}
