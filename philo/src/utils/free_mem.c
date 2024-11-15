/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:02:58 by tgoel             #+#    #+#             */
/*   Updated: 2024/11/13 17:15:04 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

// malloced: (in __init__)
//	rules: O
//	philo: O

// malloced: (in __init__philo)
//	writing: O
//	mutex: O

// malloced: (in __init__time)
//	value_time: O

void	free_all_mutex(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->rules->nb_philo)
	{
		pthread_mutex_destroy(&(prog->philo[i].fork_right_id));
		i++;
	}
	pthread_mutex_destroy(&prog->writing);
}

void	free_mem(t_prog *prog)
{
	if (prog->rules)
		free(prog->rules);
	if (prog->philo)
		free (prog->philo);
	free_all_mutex(prog);
	if (prog->threads)
		free(prog->threads);
	if (prog->value_time)
		free(prog->value_time);
}
