/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colordefining.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:02:15 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/22 14:53:00 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORDEFINING_H
# define COLORDEFINING_H

# define FRST "\n\tUsage: ./philo"
# define SCND "\e[0;32m number_of_philosophers"
# define THRD "\e[0;33m time_to_die"
# define FRTH "\e[0;34m time_to_eat"
# define FFTH "\e[0;35m time_to_sleep"
# define SX "\e[0;36m [number_of_times_each_philosopher_must_eat]\e[0;37m"

# define P_FORKS "\e[0;35m Has taken a fork"
# define P_SLEEP "\e[0;33m Is sleeping"
# define P_EAT "\e[0;32 Is eating"

# define ALL FRST SCND THRD FRTH FFTH SX

#endif