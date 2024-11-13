/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:19:20 by tgoel             #+#    #+#             */
/*   Updated: 2024/11/12 20:15:37 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	routine(t_philo *philo)
{
	t_prog	*prog;

	prog = ft_get_prog(NULL);
	if (philo->id % 2 == 0)
		ft_usleep(400);
	pthread_create(&prog->death_check, NULL, ft_check_death, philo);
	pthread_detach(prog->death_check);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	exit(0);
}

int	create_proc(t_prog *prog)
{
	int	i;

	i = 0;
	pthread_create(&(prog->meal_check), NULL, &check_all_done, prog);
	pthread_detach(prog->meal_check);
	while (i < prog->rules.nb_philo)
	{
		prog->philo[i].pid = fork();
		if (prog->philo[i].pid == 0)
			routine(&(prog->philo[i]));
		i++;
	}
	return (0);
}

int	create_prog(t_prog *prog)
{
	prog->first_time = time_s();
	__init__sema(prog);
	sem_wait(prog->stop);
	create_proc(prog);
	sem_wait(prog->stop);
	destroy_all(prog);
	return (0);
}

int	check_arg(char **av)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j++]))
			{
				write(2, "Not a digit\n", 12);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_prog	prog;
	int		rtn;

	ft_get_prog(&prog);
	if (check_arg(argv))
		return (1);
	if (argc == 5)
		rtn = __init__(&prog, argv, 0);
	else if (argc == 6)
		rtn = __init__(&prog, argv, ft_atoi(argv[5]));
	else
	{
		write(2, "Not enough args\n", 16);
		return (1);
	}
	if (rtn)
	{
		destroy_all(&prog);
		return (1);
	}
	create_prog(&prog);
	return (0);
}
