/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:17:01 by juan              #+#    #+#             */
/*   Updated: 2021/02/07 14:17:05 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*routine(void *p_data)
{
	t_philo *philo = p_data;
	while (philo->no_limite == 0 && philo->end_eat == 0)
	{
		if (philo->perso->if_die == 1)
			return (0);
		pthread_mutex_lock(philo->perso->die);
		if (ft_check_die(philo) == 1)
			return (ft_return_die(philo));
		pthread_mutex_unlock(philo->perso->die);
		if ((philo->perso->fork_perso[philo->name_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1) ||
			(philo->name_philo == 0 && (philo->perso->fork_perso[philo->nb_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1)))
		{
			if (philo->name_philo == 0)
			{
				philo->perso->fork_perso[philo->nb_philo - 1] = 0;
				philo->perso->fork_perso[philo->name_philo] = 0;
			}
			else
			{
				philo->perso->fork_perso[philo->name_philo - 1] = 0;
				philo->perso->fork_perso[philo->name_philo] = 0;
			}
			if (philo->perso->if_die == 1)
				return (0);
			if (philo->perso->fork == 0)
				pthread_mutex_lock(philo->perso->l_fork);
			display(philo->name_philo, " has taken a fork", philo);
			philo->perso->fork -= 1;
			if (philo->perso->fork == 0)
				pthread_mutex_lock(philo->perso->r_fork);
			display(philo->name_philo, " has taken a fork", philo);
			philo->perso->fork -= 1;
			philo->perso->eating[philo->name_philo] = 1;
			philo->perso->start = 1;
			philo_eat(philo);
			philo->satiate = 1;
		}
		if (philo->perso->eating[philo->name_philo] == 1)
		{
			if (philo->first_eat == 0)
				philo->first_eat = 1;
			pthread_mutex_unlock(philo->perso->l_fork);
			philo->perso->fork += 1;
			pthread_mutex_unlock(philo->perso->r_fork);
			philo->perso->fork += 1;
			philo->perso->eating[philo->name_philo] = 0;
			philo->perso->start = 0;
			if (philo->name_philo == 0)
			{
				philo->perso->fork_perso[philo->nb_philo - 1] = 1;
				philo->perso->fork_perso[philo->name_philo] = 1;
			}
			else
			{
				philo->perso->fork_perso[philo->name_philo - 1] = 1;
				philo->perso->fork_perso[philo->name_philo] = 1;
			}
		}
		if (philo->perso->if_die == 1)
			return (0);
		if (philo->satiate == 1 && philo->first_eat == 1 && philo->nb_eat > 0)
		{
			philo->satiate = 0;
			philo_sleep(philo);
			if (philo->perso->if_die == 1)
				return (0);
			philo_think(philo);
			if (philo->perso->if_die == 1)
				return (0);
		}
	}
	// 
	// 
	// 
	// 
	while (philo->no_limite == 1 && philo->dead == 0)
	{
		if (philo->perso->if_die == 1)
			return (0);
		pthread_mutex_lock(philo->perso->die);
		if (ft_check_die(philo) == 1)
			return (ft_return_die(philo));
		pthread_mutex_unlock(philo->perso->die);
		if ((philo->perso->fork_perso[philo->name_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1) ||
			(philo->name_philo == 0 && (philo->perso->fork_perso[philo->nb_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1)))
		{
			if (philo->name_philo == 0)
			{
				philo->perso->fork_perso[philo->nb_philo - 1] = 0;
				philo->perso->fork_perso[philo->name_philo] = 0;
			}
			else
			{
				philo->perso->fork_perso[philo->name_philo - 1] = 0;
				philo->perso->fork_perso[philo->name_philo] = 0;
			}
			if (philo->perso->if_die == 1)
				return (0);
			if (philo->perso->fork == 0)
				pthread_mutex_lock(philo->perso->l_fork);
			display(philo->name_philo, " has taken a fork", philo);
			philo->perso->fork -= 1;
			if (philo->perso->fork == 0)
				pthread_mutex_lock(philo->perso->r_fork);
			display(philo->name_philo, " has taken a fork", philo);
			philo->perso->fork -= 1;
			philo->perso->eating[philo->name_philo] = 1;
			philo->perso->start = 1;
			philo_eat(philo);
			philo->satiate = 1;
		}
		if (philo->perso->eating[philo->name_philo] == 1)
		{
			if (philo->first_eat == 0)
				philo->first_eat = 1;
			pthread_mutex_unlock(philo->perso->l_fork);
			philo->perso->fork += 1;
			pthread_mutex_unlock(philo->perso->r_fork);
			philo->perso->fork += 1;
			philo->perso->eating[philo->name_philo] = 0;
			philo->perso->start = 0;
			if (philo->name_philo == 0)
			{
				philo->perso->fork_perso[philo->nb_philo - 1] = 1;
				philo->perso->fork_perso[philo->name_philo] = 1;
			}
			else
			{
				philo->perso->fork_perso[philo->name_philo - 1] = 1;
				philo->perso->fork_perso[philo->name_philo] = 1;
			}
		}
		if (philo->perso->if_die == 1)
			return (0);
		if (philo->satiate == 1 && philo->first_eat == 1)
		{
			philo->satiate = 0;
			philo_sleep(philo);
			if (philo->perso->if_die == 1)
				return (0);
			philo_think(philo);
			if (philo->perso->if_die == 1)
				return (0);
		}
	}
	return (0);
}
