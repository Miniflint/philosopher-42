/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:06:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/01 22:41:09 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	create_threads(t_prog *prog)
{
	int		i;
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
	i = 0;
	while (i < prog->rules->nb_philo)
		if (pthread_join(prog->threads[i++], &rtn_val))
		{
			printf("===========================================\n");
			return (0);
		}
	if (rtn_val)
		return (1);
	return (0);
}

static void	error_arg(void)
{
	write(2, "./philo [error]", ft_strlen("./philo [error]"));
	write(2, FRST, ft_strlen(FRST));
	write(2, SCND, ft_strlen(SCND));
	write(2, THRD, ft_strlen(THRD));
	write(2, FRTH, ft_strlen(FRTH));
	write(2, FFTH, ft_strlen(FFTH));
	write(2, SX, ft_strlen(SX));
	write(2, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		c_init;
	t_prog	prog;

	c_init = 1;
	if (argc < 5 || argc > 6)
	{
		error_arg();
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
