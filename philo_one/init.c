#include "philo_one.h"

int			ft_init_var(int nb_philo, t_philo *philo, char **argv, int i, struct timeval start_time)
{
	philo[i].first_eat = 0;
	philo[i].start_time = start_time;
	philo[i].nb_philo = nb_philo;
	philo[i].time_die = ft_atoi(argv[2]);
	philo[i].time_eat = ft_atoi(argv[3]);
	philo[i].time_sleep = ft_atoi(argv[4]);
	philo[i].end_eat = 0;
	philo[i].name_philo = i;
	philo[i].dead = 0;
	philo[i].philo_die = 0;
	philo[i].satiate = 0;
	if (argv[5] != NULL)
	{
		philo[i].nb_eat = ft_atoi(argv[5]);
		philo[i].no_limite = 0;
	}
	else
		philo[i].no_limite = 1;
	return (0);
}

int			ft_malloc_struct(int nb_philo, t_init *init)
{
	if (!(init->philo = malloc(sizeof(t_philo) * nb_philo + 1)))
	    return (-1);
	if (!(init->perso = malloc(sizeof(t_perso))))
		return (-1);
	if (!(init->perso->r_fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
	    return (-1);
	if (!(init->perso->l_fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
	    return (-1);
	if (!(init->perso->talk = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
	    return (-1);
	if (!(init->perso->die = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
	    return (-1);
	init->perso->fork = nb_philo;
	init->perso->if_die = 0;
	init->perso->start = 0;
	if (!(init->perso->eating = (int *)malloc(sizeof(int) * nb_philo + 1)))
	    return (-1);
	if (!(init->perso->fork_perso = (int *)malloc(sizeof(int) * nb_philo + 1)))
		return (-1);
	return (0);
}
