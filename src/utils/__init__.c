/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:19:00 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 06:54:39 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static void	set_time(t_prog *prog)
{
	t_timeval	time_value;

	prog->time = &time_value;
	prog->time->start_time = gettimeofday(prog->time, NULL);
  printf("seconds : %ld\nmicro seconds : %ld",
  		prog->time->tv_sec, prog->time->tv_usec);
}

void	__init__(t_prog *prog, char **args)
{
	pthread_t	threads;

	set_time(prog);
	prog->nb_philo = ft_strdup(args[1]);
	prog->t_die = ft_strdup(args[2]);
	prog->t_eat = ft_strdup(args[3]);
	prog->t_sleep = ft_strdup(args[4]);
	if (prog->max_eat)
		prog->nb_eat_r = ft_strdup(args[5]);
	prog->thread = &threads;
}