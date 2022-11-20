/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:44:05 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 16:56:39 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	unlock_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->fork_right_id))
		return (1);
	if (pthread_mutex_unlock(philo->fork_left_id))
		return (1);
	return (0);
}

int	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_right_id);
	writing(philo, P_FORKS);
	pthread_mutex_lock(philo->fork_left_id);
	writing(philo, P_FORKS);
	return (0);
}

int	eating(t_philo *philo)
{
	t_prog			*prog;

	prog = philo->backup;
	if (taking_fork(philo))
		return (1);
	philo->ate = philo->ate + 1;
	philo->last_meal = time_s();
	ft_usleep(philo->backup->rules->time_eat);
	unlock_fork(philo);
	if (writing(philo, P_EAT))
		if (unlock_fork(philo))
			return (1);
	if (prog->rules->died)
		return (1);
	return (0);
}
