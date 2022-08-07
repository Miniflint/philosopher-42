/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:02:04 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/01 20:44:54 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	get_diff(struct timeval *start)
{
	struct timeval	now;
	double			sec;
	double			usec;

	gettimeofday(&now, NULL);
	sec = now.tv_sec - start->tv_sec;
	usec = now.tv_usec - start->tv_usec;
	return (sec * 1000000 + usec);
}

void	ft_usleep(long time_to_wait)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (get_diff(&start) < (int)time_to_wait)
		usleep(10);
}

long long	time_s(void)
{
	int				i;
	struct timeval	t;

	i = gettimeofday(&t, NULL);
	if (i)
		return (-1);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
