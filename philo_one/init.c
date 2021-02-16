/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:04:16 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/16 09:29:49 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		ft_init_two(int nb_p, t_init *init, char **argv, struct timeval	st)
{
	int i;

	i = 0;
	while (i < nb_p)
	{
		ft_init_var(nb_p, init->philo, argv, i);
		init->philo[i].start_time = st;
		gettimeofday(&init->philo[i].ms_died, NULL);
		init->philo[i].p = init->p;
		init->philo[i].p->fp[i] = 1;
		init->philo[i].p->eating[i] = 0;
		i++;
	}
	pthread_mutex_init(init->p->l_fork, NULL);
	pthread_mutex_init(init->p->talk, NULL);
	pthread_mutex_init(init->p->r_fork, NULL);
	pthread_mutex_init(init->p->die, NULL);
}

int			ft_init_var(int nb_philo, t_philo *philo, char **argv, int i)
{
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
	if (!(init->p = malloc(sizeof(t_perso))))
		return (-1);
	if (!(init->p->r_fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)
														* nb_philo + 1)))
		return (-1);
	if (!(init->p->l_fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)
														* nb_philo + 1)))
		return (-1);
	if (!(init->p->talk = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
		return (-1);
	if (!(init->p->die = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
		return (-1);
	init->p->fork = nb_philo;
	init->p->if_die = 0;
	if (!(init->p->eating = (int *)malloc(sizeof(int) * nb_philo + 1)))
		return (-1);
	if (!(init->p->fp = (int *)malloc(sizeof(int) * nb_philo + 1)))
		return (-1);
	return (0);
}
