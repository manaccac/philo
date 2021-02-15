/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:53:34 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/15 11:54:07 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		ft_init_two(int nb_p, t_init *init, char **argv, struct timeval	st)
{
	int i;

	i = 0;
	while (i < nb_p)
	{
		init->philo[i].start_time = st;
		ft_init_var(nb_p, init->philo, argv, i);
		gettimeofday(&init->philo[i].ms_died, NULL);
		init->philo[i].perso = init->perso;
		init->philo[i].perso->fork_perso[i] = 1;
		init->philo[i].perso->eating[i] = 0;
		i++;
	}
	sem_unlink("/fork");
	sem_unlink("/die");
	sem_unlink("/talk");
	init->perso->s_talk = sem_open("/talk", O_CREAT | O_EXCL, S_IRWXU, 1);
	init->perso->s_die = sem_open("/die", O_CREAT | O_EXCL, S_IRWXU, 1);
	init->perso->s_fork = sem_open("/fork",
									O_CREAT | O_EXCL, S_IRWXU, nb_p + 1);
}

int			ft_init_var(int nb_philo, t_philo *philo, char **argv, int i)
{
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
	init->perso->fork = nb_philo;
	init->perso->if_die = 0;
	if (!(init->perso->eating = (int *)malloc(sizeof(int) * nb_philo + 1)))
		return (-1);
	if (!(init->perso->fork_perso = (int *)malloc(sizeof(int) * nb_philo + 1)))
		return (-1);
	return (0);
}
