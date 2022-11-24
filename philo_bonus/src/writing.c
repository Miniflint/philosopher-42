/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:06:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/24 01:49:39 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

void	writing(t_philo *philo, char *str)
{
	t_prog	*prog;

	prog = ft_get_prog(NULL);
	sem_wait(prog->write);
	printf("%lld\tPhilo_%d %s\n", time_s() - prog->first_time,
		philo->id + 1, str);
	if (!prog->rules.died)
		sem_post(prog->write);
}

void	writing_eating(t_philo *philo, char *str, int nb)
{
	t_prog	*prog;

	prog = ft_get_prog(NULL);
	sem_wait(prog->write);
	printf("%lld\tPhilo_%d %s | %d times\n", time_s() - prog->first_time,
		philo->id + 1, str, nb + 1);
	if (!prog->rules.died)
		sem_post(prog->write);
}
