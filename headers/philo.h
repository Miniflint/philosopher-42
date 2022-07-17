/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:49:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 06:55:34 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philostruct.h"
# include <pthread.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>

# include "philostruct.h"

/* main */


/* utils */
int		ft_strlen(char *str);
char	*ft_strup(char *str);
void	__init__(t_prog *prog, char **args);
	/* errors */
void	handle_error(char *str);

#endif