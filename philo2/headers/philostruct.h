/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philostruct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:07:59 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/20 13:59:58 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSTRUCT_H
# define PHILOSTRUCT_H

#include "philo.h"

# define E_BASE "./philo [error]: "
# define W_ERROR write(2, E_BASE, ft_strlen(E_BASE))

typedef struct S_philo
{
	int	id;
	int	fork_right_id;
	int	fork_left_id;
}	t_philo;

typedef struct S_rule
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_t_eat;
	int	add_max_eat;
}	t_rules;

typedef struct S_prog
{
	long long		time_start;
	t_rules			*rules;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}	t_prog;

#endif