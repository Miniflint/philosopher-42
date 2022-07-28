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
	actualize_time(philo->backup);
	if (pthread_mutex_lock(&philo->fork_right_id))
		return (1);
	if (pthread_mutex_lock(philo->fork_left_id))
		return (1);
	if (writing(philo, "Has taken a fork"))
		return (1);
	if (writing(philo, "Has taken a fork"))
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

// last meal = temp mtn - dernier repas pour avoir la diff

int	eating(t_philo *philo)
{
	t_prog *prog;

	if (taking_fork(philo))
		return (1);
	prog = philo->backup;
//	if (philo->last_meal > prog->rules->time_die)
//	{
//		writing(philo, "Is dead");
//		prog->rules->died = 1;
//		return (1);
//	}
	if (writing(philo, "Is eating"))
		return (1);
	philo->ate += 1;
	ft_usleep(philo->backup->rules->time_eat);
	philo->last_meal = (time_s() - prog->time_start) - philo->last_meal;
	if (unlock_fork(philo))
		return (1);
	return (0);
}

