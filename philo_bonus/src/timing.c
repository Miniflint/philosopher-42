/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:17:20 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/23 21:17:29 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	get_diff(struct timeval *start)
{
	struct timeval	now;
	double			sec;
	double			usec;

	gettimeofday(&now, NULL);
	sec = now.tv_sec - start->tv_sec;
	usec = now.tv_usec - start->tv_usec;
	return (sec * 1000000 + usec);
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
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
