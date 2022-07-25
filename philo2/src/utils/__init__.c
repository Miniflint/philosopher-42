/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:19:00 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/25 16:39:40 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	__init__time(t_prog *prog)
{
	int c_time;

	prog->value_time = malloc(sizeof(struct timeval));
	if (!prog->value_time)
	{
		handle_error("Error mallocing timeval");
		return (0);
	}
	c_time = gettimeofday(prog->value_time, NULL);
	prog->time_start = (long long)prog->value_time->tv_usec;
	return (c_time + 1);
}

static void	__init__philo(t_philo *philo, int amount_philo, t_prog *prog)
{
	int	i;

	i = 0;
	while (i < amount_philo)
	{
		philo[i].id = i + 1;
		philo[i].backup = prog;
		philo[i].ate = 0;
		pthread_mutex_init(&philo[i].fork_right_id, NULL);
		i++;
	}
	i = 0;
	while (i < amount_philo)
	{
		if (i == amount_philo - 1)
			philo[i].fork_left_id = &philo[0].fork_right_id;
		else
			philo[i].fork_left_id = &philo[i + 1].fork_right_id;
		i++;
	}
}

static void	__init__rules(t_rules *rules, char **argv)
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (rules->add_max_eat)
		rules->nb_t_eat = ft_atoi(argv[5]);
}

static int	create_size_t(t_prog *prog)
{
	prog->threads = malloc(sizeof(pthread_t) * prog->rules->nb_philo);
	if (prog->threads)
		return (1);
	handle_error("Could not malloc threads");
	return (0);
}

int	__init__(t_prog *prog, char **args, int	max_eat)
{
	int			c_time;
	t_philo		*philo;
	t_rules		*rules;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		handle_error("Error mallocing: rules");
	rules->add_max_eat = max_eat;
	__init__rules(rules, args);
	philo = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!philo)
		handle_error("Error mallocing: philo");
	__init__philo(philo, rules->nb_philo, prog);
	prog->philo = philo;
	prog->rules = rules;
	c_time = __init__time(prog);
	if (!c_time)
		handle_error("Error getting the time");
	if (!c_time || !philo || !rules || !create_size_t(prog))
		return (1);
	return (0);
}

