/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philostruct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:07:59 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/24 00:30:26 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSTRUCT_H
# define PHILOSTRUCT_H

# include "philo.h"

# define E_BASE "./philo [error]: "

typedef struct S_philo
{
	int				id;
	int				ate;
	int				done_eating;
	long long		last_meal;
	struct S_prog	*backup;
	pthread_mutex_t	fork_right_id;
	pthread_mutex_t	*fork_left_id;
}	t_philo;

typedef struct S_rule
{
	int	died;
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
	long long		time_now;
	int				all_ate;
	struct timeval	*value_time;
	pthread_mutex_t	writing;
	pthread_t		*threads;
	t_rules			*rules;
	t_philo			*philo;
}	t_prog;

#endif
