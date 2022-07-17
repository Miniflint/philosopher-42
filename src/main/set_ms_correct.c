/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ms_correct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 07:26:27 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 07:37:55 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	set_correct_time(t_prog *prog)
{
	int	i;
	int	current_ex;

	i = prog->times_values->start_time_ms;
	gettimeofday(prog->time, NULL);
	prog->times_values->current_time_ms = prog->time->tv_usec;
	current_ex = prog->times_values->current_time_ms - i;
	return (current_ex);
}