#include "philo_one.h"

int            main(int argc, char **argv)
{
    t_philo *philo = NULL;
    struct timeval start_time;
    int nb_philo = ft_atoi(argv[1]);
    int i = 0;
    if (nb_philo <= 1)
    {
        ft_putstr("Le nombre de philo doit être supérieur a 1");
        return (-1);
    }
    if (!(philo = malloc(sizeof(philo) * nb_philo)))
        return (0);
    gettimeofday(&start_time, NULL);
    while (i < nb_philo)
    {

        philo[i].start_time = start_time;
        philo[i].nb_philo = nb_philo;
        philo[i].time_die = ft_atoi(argv[2]);
        philo[i].time_eat = ft_atoi(argv[3]);
        philo[i].time_sleep = ft_atoi(argv[4]);
        philo[i].end_eat = 0;
        philo[i].name_philo = i;
        if (argc == 6)
            philo[i].nb_eat = ft_atoi(argv[5]);
        i++;
    }
    pthread_t thread_philo[nb_philo];
    int ret = 0;
    i = 0;

    while (i < nb_philo)
    {
        ret = pthread_create(&thread_philo[i], NULL, routine, &philo[i]);
        i++;
    }
    i = 0;
    while (i < nb_philo)
    {
        pthread_join(thread_philo[i], NULL);
        i++;
    }
    return (ret);
}
