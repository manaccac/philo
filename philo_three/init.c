/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:04:06 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/18 14:30:41 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			ft_init_var(t_init *init, int nb_philo, t_philo *philo, char **argv, int i, struct timeval start_time)
{
	(void)init;
	// philo[i].s_die = init->s_die;
	// philo[i].s_fork = init->s_fork;
	philo[i].s_talk = init->s_talk;
	// philo[i].s_management = init->s_management;
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
	philo[i].reload = 0;
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
	init->philo->fork = nb_philo;
	init->philo->if_die = 0;
	if (!(init->eating = (int *)malloc(sizeof(int) * nb_philo + 1)))
	    return (-1);
	if (!(init->fp = (int *)malloc(sizeof(int) * nb_philo + 1)))
		return (-1);
	return (0);
}
