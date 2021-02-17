/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:48:32 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/17 10:41:25 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		*routine(t_philo *philo, t_init *init)
{
	// t_philo *philo = p_data;
	while (philo->no_limite == 0 && philo->nb_eat > 0 && philo->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
		{
			// dprintf(1, "np = %d\n", philo->np);
			// sem_wait(init->s_prio);
			sem_wait(init->s_talk);
			philo->philo_die = 1;
			if (philo->if_die == 0)
			{
				philo->if_die = 1;
				display(philo->np, " died", philo, init);
			}
			return (0);
		}
		if (philo->if_die == 1)
			return (0);
		philo->fork -= 2;
		sem_wait(init->s_fork);
		display(philo->np, " has taken a fork", philo, init);
		display(philo->np, " has taken a fork", philo, init);
		if (philo->if_die == 1)
		{
			sem_post(init->s_fork);
			return (0);
		}
		philo_eat(philo, init);
		sem_post(init->s_fork);
		philo->fork += 2;
		if (philo->nb_eat > 0)
		{
			if (philo->if_die == 1)
				return (0);
			philo_sleep(philo, init);
			if (philo->if_die == 1)
				return (0);
			display(philo->np, " is thinking", philo, init);
		}
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
			return (0);
		}
		if (philo->if_die == 1)
			return (0);
		philo->fork -= 2;
		sem_wait(init->s_fork);
		display(philo->np, " has taken a fork", philo, init);
		display(philo->np, " has taken a fork", philo, init);
		if (philo->if_die == 1)
		{
			sem_post(init->s_fork);
			return (0);
		}
		philo_eat(philo, init);
		philo->fork += 2;
		sem_post(init->s_fork);
		if (philo->if_die == 1)
			return (0);
		philo_sleep(philo, init);
		if (philo->if_die == 1)
			return (0);
		display(philo->np, " is thinking", philo, init);
	}
	return (0);
}
