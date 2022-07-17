/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:49:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 05:22:05 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philostruct.h"
# include "pthread.h"
# include "unistd.h"

/* main */


/* utils */
	/* errors */
void	handle_error(char *str);
int		ft_strlen(char *str);

#endif