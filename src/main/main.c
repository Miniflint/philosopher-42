/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 05:08:17 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 07:40:32 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	main(int argc, char **argv)
{
	t_prog		prog;
	prog.max_eat = argc - 4;
	if (prog.max_eat < 0)
		handle_error("Not enough args");
	__init__(&prog, argv);
	usleep(20000);
	prog.times_values->current_prog_time = set_correct_time(&prog);
	usleep(20000);
	prog.times_values->current_prog_time = set_correct_time(&prog);
	printf("current: %lld\n", prog.times_values->current_prog_time);
}