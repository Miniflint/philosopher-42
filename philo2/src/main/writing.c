/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:02:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/01 20:59:45 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	writing(t_philo *philo, char *str)
{
	t_prog		*prog;

	if (philo->backup->rules->died)
		return (1);
	pthread_mutex_lock(&philo->backup->writing);
	if (philo->backup->rules->died)
		return (1);
	prog = philo->backup;
	//printf("\n");
	if (philo->id >= 10 && !prog->rules->died)
		printf("%lli \tphilo_%i %s\n",
			time_s() - prog->time_start, philo->id, str);
	else if (philo->id < 10 && !prog->rules->died)
		printf("%lli \tphilo_%i\t %s\n",
			time_s() - prog->time_start, philo->id, str);
	pthread_mutex_unlock(&prog->writing);
	return (0);
}
