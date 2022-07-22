/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:19:00 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/22 13:42:16 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

/*
Rules creator: Done
philo creator: Done
Mutex creator: idk what to do yet

i think mutex should be on 
*/

void	__init__mutex(pthread_mutex_t *forks, int amount_philo)
{
	int	i;

	i = 0;
	while (i < amount_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	__init__philo(t_philo *philo, int amount_philo)
{
	int	i;

	i = 0;
	while (i < amount_philo)
	{
		philo[i].id = i;
		pthread_mutex_init(&philo[i].fork_right_id, NULL);
		i++;
	}
	i = 0;
	while (i < amount_philo)
	{
		pthread_mutex_init(philo[i + 1].fork_left_id, NULL);
		if (i == 0)
			pthread_mutex_init(philo[amount_philo - 1].fork_left_id, NULL);
		if (i == amount_philo - 1)
			pthread_mutex_init(philo[0].fork_left_id, NULL);
	}
	// while (i < amount_philo)
	// {
	// 	philo[i].id = i;
	// 	philo[i].fork_left_id = i + 1;
	// 	philo[i].fork_right_id = i;

	// 	if (i == 0)
	// 		philo[i].fork_left_id = amount_philo - 1;
	// 	if (i == amount_philo - 1)
	// 		philo[i].fork_left_id = 0;
	// 	i++;
	// }
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

void	__init__(t_prog *prog, char **args, int	max_eat)
{
	t_philo			*philo;
	t_rules			*rules;

	rules = malloc(sizeof(rules));
	if (!rules)
		handle_error("Could not malloc");
	rules->add_max_eat = max_eat;
	__init__rules(rules, args);
	philo = malloc(sizeof(philo) * rules->nb_philo);
	__init__philo(philo, rules->nb_philo);
	prog->philo = philo;
	prog->rules = rules;
}
