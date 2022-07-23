/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:06:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/22 14:25:10 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	main(int argc, char **argv)
{
	t_prog	prog;

	if (argc < 2 || argc > 6)
		handle_error(ALL);
	if (argc == 6)
		__init__(&prog, argv, ft_atoi(argv[5]));
	else if (argc == 5)
		__init__(&prog, argv, 0);
	free_mem(&prog);
}
