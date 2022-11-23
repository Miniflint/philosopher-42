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

int     ft_atoi(char *str); 
int     __init__(t_prog *prog, char **argv, int max_eat);
t_prog  *ft_get_prog(t_prog *new_prog);
void	ft_print_message(int id, t_philo *philo);

#endif
