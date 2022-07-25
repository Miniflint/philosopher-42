/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:06:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/24 22:55:54 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	create_threads(t_prog *prog)
{
	int	i;
	t_philo	*philos;

	philos = prog->philo;
	i = 0;
	while (i < prog->rules->nb_philo)
	{
		if (pthread_create(&prog->threads[i], NULL, &routine, &philos[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < prog->rules->nb_philo)
		if (pthread_join(prog->threads[i++], NULL))
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		c_init;
	t_prog	prog;

	c_init = 1;
	if (argc < 5 || argc > 6)
	{
		handle_error(ALL);
		return (1);
	}
	if (argc == 6)
		c_init = __init__(&prog, argv, ft_atoi(argv[5]));
	else if (argc == 5)
		c_init = __init__(&prog, argv, 0);
	if (!create_threads(&prog))
	{
		handle_error("Error creating / joining threads");
		return (1);
	}
	free_mem(&prog);
	return (c_init);
}

