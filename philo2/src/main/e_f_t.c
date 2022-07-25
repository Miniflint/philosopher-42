/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_f_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:44:05 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/25 17:06:10 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	taking_fork(t_philo *philo)
{
	printf("philo %i\tHas taken a fork\n", philo->id);
	if (pthread_mutex_lock(&philo->fork_right_id))
		return (1);
	printf("philo %i\tHas taken a fork\n", philo->id);
	if (pthread_mutex_lock(philo->fork_left_id))
		return (1);
	return (0);
}

int	unlock_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->fork_right_id))
		return (1);
	if (pthread_mutex_unlock(philo->fork_left_id))
		return (1);
	return (0);
}

int	eating(t_philo *philo)
{
	if (taking_fork(philo))
		return (1);
	printf("philo %i\tIs eating\n", philo->id);
	if (unlock_fork(philo))
		return (1);
	return (0);
}