/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colordefining.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:02:15 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/20 13:12:56 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORDEFINING_H
# define COLORDEFINING_H

# define SCND "\e[0;32mnumber_of_philosophers"
# define THRD "\e[0;33m time_to_die"
# define FRTH "\e[0;34m time_to_eat"
# define FFTH "\e[0;35m time_to_sleep"
# define SX "\e[0;36m [number_of_times_each_philosopher_must_eat]\e[0;37m"

# define ALL SCND THRD FRTH FFTH SX

#endif