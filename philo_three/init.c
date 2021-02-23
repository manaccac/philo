/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:04:06 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 11:28:43 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int				ft_init_var(t_init *init, t_philo *philo, char **argv, int i)
{
	philo[i].s_talk = init->s_talk;
	philo[i].nb_philo = ft_atoi(argv[1]);
	philo[i].time_die = ft_atoi(argv[2]);
	philo[i].time_eat = ft_atoi(argv[3]);
	philo[i].time_sleep = ft_atoi(argv[4]);
	philo[i].end_eat = 0;
	philo[i].np = i;
	philo[i].dead = 0;
	philo[i].philo_die = 0;
	if (argv[5] != NULL)
	{
		philo[i].nb_eat = ft_atoi(argv[5]);
		philo[i].no_limite = 0;
	}
	else
		philo[i].no_limite = 1;
	return (0);
}

int				ft_malloc_struct(int nb_philo, t_init *init)
{
	if (!(init->philo = malloc(sizeof(t_philo) * nb_philo + 1)))
		return (-1);
	init->philo->fork = nb_philo;
	init->philo->if_die = 0;
	return (0);
}

void			ft_init_sem(int nb_philo, t_init *init)
{
	int i;

	i = 0;
	sem_unlink("/fork");
	sem_unlink("/die");
	sem_unlink("/talk");
	sem_unlink("/eat");
	sem_unlink("/talk_die");
	init->s_talk = sem_open("/talk", O_CREAT | O_EXCL, S_IRWXU, 1);
	init->s_talk_die = sem_open("/talk_die", O_CREAT | O_EXCL, S_IRWXU, 1);
	while (i < nb_philo)
	{
		init->philo[i].s_talk_die = init->s_talk_die;
		i++;
	}
	init->s_eat = sem_open("/eat", O_CREAT | O_EXCL, S_IRWXU, nb_philo / 2);
	init->s_die = sem_open("/die", O_CREAT | O_EXCL, S_IRWXU, 1);
	init->s_fork = sem_open("/fork", O_CREAT | O_EXCL, S_IRWXU, nb_philo / 2);
}
