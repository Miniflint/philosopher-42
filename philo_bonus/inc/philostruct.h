/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philostruct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:57:33 by tgoel             #+#    #+#             */
/*   Updated: 2024/11/12 20:15:37 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSTRUCT_H
# define PHILOSTRUCT_H

# include "philo.h"

typedef struct S_philo
{
	int			id;
	int			ate;
	int			dead;
	int			done_eating;
	long long	last_meal;
	pid_t		pid;
}	t_philo;

typedef struct S_rules
{
	int	nb_philo;
	int	time_death;
	int	time_eat;
	int	time_sleep;
	int	nb_eat;
	int	died;
	int	add_max_eat;
}	t_rules;

typedef struct S_prog
{
	int			all_done;
	long long	first_time;
	t_rules		rules;
	t_philo		*philo;
	pthread_t	death_check;
	pthread_t	meal_check;
	sem_t		*write;
	sem_t		*forks;
	sem_t		*stop;
	sem_t		*death;
	sem_t		*done;
}	t_prog;

#endif
