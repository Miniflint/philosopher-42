/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philostruct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 05:15:04 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 06:47:48 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSTRUCT_H
# define PHILOSTRUCT_H

# include "philo.h"

/* define errors */
# define E_BASE "./philo [error]: "

/* win execution time */
# define DSTRLEN(s) (sizeof(s)/sizeof(s[0]) - sizeof(s[0]))
# define W_ERROR write(2, E_BASE, DSTRLEN(E_BASE))

typedef struct S_timeval
{
	int			start_time;
	time_t		tv_sec;
	suseconds_t	tv_usec;
}	t_timeval;

typedef struct	S_prog
{
	int	max_eat;
	int	nb_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_eat_r;
	pthread_t *thread;
	t_timeval *time;
}	t_prog;

#endif