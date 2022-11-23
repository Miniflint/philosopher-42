void	ft_print_message(t_philo *philo, char *str)
{
    t_prog          *backup;
	unsigned int	time;

    backup = ft_get_prog(NULL);
	time = ft_get_time() - philo->data->start;
	sem_wait(philo->data->message);
	printf("%u\t%d %s\n", time, philo->index + 1, str);
    if (!backup->died)
	    sem_post(philo->data->message);
}