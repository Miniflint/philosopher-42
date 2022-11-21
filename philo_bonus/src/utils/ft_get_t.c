#include "../../inc/philo.h"

t_prog *ft_get_prog(t_prog *new_prog)
{
    static t_prog   *prog;

    if (new_prog)
        prog = new_prog;
    return (prog);
}
