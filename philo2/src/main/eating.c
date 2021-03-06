/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:44:05 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/01 20:52:33 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	taking_fork(t_philo *philo)
{
	if (philo->backup->rules->died)
		return (1);
	if (pthread_mutex_lock(&philo->fork_right_id))
		return (1);
	if (pthread_mutex_lock(philo->fork_left_id))
		return (1);
	if (writing(philo, "Has taken a fork"))
		return (1);
	if (writing(philo, "Has taken a fork"))
		return (1);
	if (philo->backup->rules->died)
		return (1);
	return (0);
}

int	unlock_fork(t_philo *philo)
{
	if (philo->backup->rules->died)
		return (1);
	if (pthread_mutex_unlock(&philo->fork_right_id))
		return (1);
	if (pthread_mutex_unlock(philo->fork_left_id))
		return (1);
	if (philo->backup->rules->died)
		return (1);
	return (0);
}

int	eating(t_philo *philo)
{
	t_prog	*prog;

	prog = philo->backup;
	if (prog->rules->died)
		return (1);
	if (philo->last_meal + prog->rules->time_die
		< (time_s() - prog->time_start))
	{
		if (writing(philo, "Is dead"))
			return (1);
		prog->rules->died = 1;
		return (1);
	}
	if (taking_fork(philo))
		return (1);
	if (writing(philo, "Is eating"))
		return (1);
	philo->ate += 1;
	philo->last_meal = (time_s() - prog->time_start);
	ft_usleep(philo->backup->rules->time_eat);
	if (unlock_fork(philo))
		return (1);
	if (prog->rules->died)
		return (1);
	return (0);
}
