/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:49:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 07:30:30 by tgoel            ###   ########.fr       */
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

# include "philostruct.h"

/* main */
int		set_correct_time(t_prog *prog);

/* utils */
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_atoi(char *str);
	/* errors */
void	handle_error(char *str);
	/* init */
void	__init__(t_prog *prog, char **args);

#endif