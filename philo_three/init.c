
#include "philo_three.h"

int			ft_init_var(int nb_philo, t_philo *philo, char **argv, int i, struct timeval start_time)
{
	philo[i].start_time = start_time;
	philo[i].nb_philo = nb_philo;
	philo[i].time_die = ft_atoi(argv[2]);
	philo[i].time_eat = ft_atoi(argv[3]);
	philo[i].time_sleep = ft_atoi(argv[4]);
	philo[i].end_eat = 0;
	philo[i].np = i;
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
	init->p->fork = nb_philo;
	init->p->if_die = 0;
	// init->p->i = 0;
	if (!(init->p->eating = (int *)malloc(sizeof(int) * nb_philo + 1)))
	    return (-1);
	// if (!(init->philo->pid = (int *)malloc(sizeof(int) * nb_philo + 1)))
	// 	return (-1);
	if (!(init->p->fp = (int *)malloc(sizeof(int) * nb_philo + 1)))
		return (-1);
	return (0);
}
