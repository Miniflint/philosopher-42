/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 05:08:17 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 06:54:37 by tgoel            ###   ########.fr       */
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
}