/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philostruct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 05:15:04 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 10:57:29 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSTRUCT_H
# define PHILOSTRUCT_H

# include "philo.h"

/* define errors */
# define E_BASE "./philo [error]: "

/* win execution time */
# define W_ERROR write(2, E_BASE, ft_strlen(E_BASE))

typedef struct	S_times
{
	long long	start_time_ms;
	long long	current_time_ms;
	long long	current_prog_time;
}	t_times;

typedef struct	S_prog
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat_r;
	pthread_t		*thread;
	t_times			*times_values;
	struct timeval	*time;
}	t_prog;

#endif