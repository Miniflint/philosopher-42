#include "../inc/philo.h"
#include <stdio.h>

void print_rules()
{
    t_rules *rules;

    rules = &(ft_get_prog(NULL)->rules);
    printf("%d - %d - %d\n", rules->nb_philo, rules->time_death, rules->time_eat);
    printf("%d - %d - %d\n", rules->time_sleep, rules->nb_eat, rules->died);
}

int main(int argc, char **argv)
{
    t_prog  prog;

    ft_get_prog(&prog);
    if (argc == 5)
        __init__(&prog, argv, 0);
    else if (argc == 6)
        __init__(&prog, argv, ft_atoi(argv[5]));
    else
        return (1);
    print_rules();
    return (0);
}