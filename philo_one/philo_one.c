
#include "philo_one.h"

int            main(int argc, char **argv)
{
    t_philo *philo = NULL;
    t_perso *perso = NULL;
    struct timeval start_time;
    int nb_philo = ft_atoi(argv[1]);
    int i = 0;
    if (nb_philo <= 1)
    {
        ft_putstr("Le nombre de philo doit être supérieur a 1");
        return (-1);
    }
    if (!(philo = malloc(sizeof(t_philo) * nb_philo + 1)))
        return (-1);
    gettimeofday(&start_time, NULL);
	if (!(perso = malloc(sizeof(t_perso))))
		return (-1);
    if (!(perso->r_fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
        return (-1);
    if (!(perso->l_fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
        return (-1);
	perso->fork = nb_philo;
    if (!(perso->eating = (int *)malloc(sizeof(int) * nb_philo + 1)))
        return (-1);
    while (i < nb_philo)
    {
        philo[i].start_time = start_time;
        philo[i].nb_philo = nb_philo;
        philo[i].time_die = ft_atoi(argv[2]);
        philo[i].time_eat = ft_atoi(argv[3]);
        philo[i].time_sleep = ft_atoi(argv[4]);
        philo[i].end_eat = 0;
        philo[i].name_philo = i;
        philo[i].dead = 0;
        if (argc == 6)
        {
            philo[i].nb_eat = ft_atoi(argv[5]);
            philo[i].no_limite = 0;
        }
        else
			philo[i].no_limite = 1;
		gettimeofday(&philo[i].ms_died, NULL);
		philo[i].perso = perso;
		if (!(perso->eating[i] = (int)malloc(sizeof(int))))
			return (-1);
		philo[i].perso->eating[i] = 0;
        i++;
    }
	pthread_mutex_init(perso->l_fork, NULL);
	pthread_mutex_init(perso->r_fork, NULL);
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
