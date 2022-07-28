/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:06:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/25 16:41:09 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	create_threads(t_prog *prog)
{
	int	i;
	t_philo	*philos;
	void	*rtn_val;

	rtn_val = NULL;
	philos = prog->philo;
	i = 0;
	while (i < prog->rules->nb_philo)
	{
		if (pthread_create(&prog->threads[i], NULL, &routine, &philos[i]))
			return (1);
		i++;
	}
	printf("I am here\n");
	i = 0;
	while (i < prog->rules->nb_philo)
		if (pthread_join(prog->threads[i++], &rtn_val))
			return (1);
	if (rtn_val)
		printf("===========================================");
	return (0);
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
	if (c_init)
		return (1);
	if (create_threads(&prog))
	{
		handle_error("Error creating / joining threads");
		free_mem(&prog);
		return (1);
	}
	free_mem(&prog);
	return (0);
}

