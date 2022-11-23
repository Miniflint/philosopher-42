/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:57:29 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/23 21:54:14 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "philostruct.h"

// UTILS
int			ft_atoi(char *str);
t_prog		*ft_get_prog(t_prog *new_prog);
int			__init__sema(t_prog *prog);
int			ft_strcmp(char *s1, char *s2);

// MAIN
int			__init__(t_prog *prog, char **argv, int max_eat);
void		writing(t_philo *philo, char *str);

// DESTROY
void		destroy_all(t_prog *prog);
void		print_id(t_prog *prog);

// TIMING
long long	time_s(void);
void		ft_usleep(long time_to_wait);
long long	time_diff(long long past, long long pres);

// ACTION
void		taking_fork(t_philo *philo);
void		unlock_fork(t_prog *prog);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		*check_all_done(void *arg);
void		*ft_check_death(void *arg);

#endif