#include "philo_one.h"

int             check_arg(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        return (put_error(ERR_ARG));
    if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0)
        return (put_error(ERR_ARG));
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
        return (put_error(ERR_ARG));
	return (1);
}

int            main(int argc, char **argv)
{
    t_init init;
    struct timeval start_time;
    int nb_philo;
    int i;
    
    if (check_arg(argc, argv) == 0)
        return (0);
    nb_philo = ft_atoi(argv[1]);
    i = 0;
    if (nb_philo <= 1)
    {
        ft_putstr("Le nombre de philo doit être supérieur a 1");
        return (-1);
    }
    if (ft_malloc_struct(nb_philo, &init) == -1)
        return (-1);
    gettimeofday(&start_time, NULL);
    while (i < nb_philo)
    {
		ft_init_var(nb_philo, init.philo, argv, i, start_time);
		gettimeofday(&init.philo[i].ms_died, NULL);
		init.philo[i].perso = init.perso;
		if (!(init.perso->fork_perso[i] = (int)malloc(sizeof(int))))
			return (-1);
		init.philo[i].perso->fork_perso[i] = 1;
		if (!(init.perso->eating[i] = (int)malloc(sizeof(int))))
			return (-1);
		init.philo[i].perso->eating[i] = 0;
        i++;
    }
    pthread_t thread_philo[nb_philo];
	pthread_mutex_init(init.perso->l_fork, NULL);
	pthread_mutex_init(init.perso->talk, NULL);
	pthread_mutex_init(init.perso->r_fork, NULL);
	pthread_mutex_init(init.perso->die, NULL);
    int ret = 0;
    i = 0;
    while (i < nb_philo)
    {
        ret = pthread_create(&thread_philo[i], NULL, routine, &init.philo[i]);
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
