/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:48:32 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/18 10:24:56 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		routine(t_philo *philo, t_init *init)
{
	while (philo->no_limite == 0 && philo->nb_eat > 0 && philo->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
		{
			sem_wait(init->s_talk);
			philo->philo_die = 1;
			if (philo->if_die == 0)
			{
				philo->if_die = 1;
				display(philo->np, " died", philo, init);
			}
			return (1);
		}
		sem_wait(init->s_fork);
		display(philo->np, " has taken a fork", philo, init);
		display(philo->np, " has taken a fork", philo, init);
		philo_eat(philo, init);
		sem_post(init->s_fork);
		if (philo->nb_eat > 0)
		{
			philo_sleep(philo, init);
			if (philo->if_die == 1)
				return (1);
			display(philo->np, " is thinking", philo, init);
		}
		// dprintf(1, "nb_eat : %d pour philo %d\n", philo->nb_eat, philo->np + 1);
	}
	//
	while (philo->no_limite == 1 && philo->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
		{
			sem_wait(init->s_talk);
			philo->philo_die = 1;
			if (philo->if_die == 0)
			{
				philo->if_die = 1;
				display(philo->np, " died", philo, init);
			}
			return (1);
		}
		sem_wait(init->s_fork);
		display(philo->np, " has taken a fork", philo, init);
		display(philo->np, " has taken a fork", philo, init);
		philo_eat(philo, init);
		sem_post(init->s_fork);
		philo_sleep(philo, init);
		if (philo->if_die == 1)
			return (1);
		display(philo->np, " is thinking", philo, init);
	}
	return (0);
}
