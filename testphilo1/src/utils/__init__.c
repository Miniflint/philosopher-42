/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:19:00 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 10:58:39 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static void	__init__current_time(t_prog *prog)
{
	struct timeval	time_value;

	prog->time = &time_value;
	gettimeofday(prog->time, NULL);
}

static void	__init__timeval(t_prog *prog)
{
	prog->times_values = malloc(sizeof(t_times));
	if (!prog->times_values)
		handle_error("Couldn't malloc");
	prog->times_values->start_time_ms = prog->time->tv_usec;
}

void	__init__(t_prog *prog, char **args, int size)
{
	pthread_t	threads;

	__init__current_time(prog);
	__init__timeval(prog);
	prog->nb_philo = ft_atoi(args[1]);
	prog->t_die = ft_atoi(args[2]);
	prog->t_eat = ft_atoi(args[3]);
	prog->t_sleep = ft_atoi(args[4]);
	if (size)
		prog->nb_eat_r = ft_atoi(args[5]);
	prog->thread = &threads;
}