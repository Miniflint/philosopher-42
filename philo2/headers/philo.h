/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:06:29 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/20 13:06:14 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
# include <sys/types.h>

# include "colordefining.h"
# include "philostruct.h"

/* utils */
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_atoi(char *str);
	/* errors */
void	handle_error(char *str);
	/* init */
void	__init__(t_prog *prog, char **args, int	max_eat);

#endif