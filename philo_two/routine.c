/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:56:08 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/15 12:04:02 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void		*routine_no_limit(t_philo *philo)
{
	while (philo->perso->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
			return (ft_check_die_two(philo));
		if (philo->perso->fork / 2 >= 1)
		{
			if (take_fork(philo) == 0)
				return (0);
			philo_eat(philo);
			philo->perso->fork += 2;
			sem_post(philo->perso->s_fork);
			if (philo->perso->if_die == 1)
				return (0);
			philo_sleep(philo);
			if (philo->perso->if_die == 1)
				return (0);
			display(philo->name_philo, " is thinking", philo);
		}
	}
	return (0);
}

void			*routine(void *p_data)
{
	t_philo *philo;

	philo = p_data;
	if (philo->no_limite == 1)
		return (routine_no_limit(philo));
	while (philo->nb_eat > 0 && philo->perso->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
			return (ft_check_die_two(philo));
		if (philo->perso->fork / 2 >= 1)
		{
			if (take_fork(philo) == 0)
				return (0);
			philo_eat(philo);
			philo->perso->fork += 2;
			sem_post(philo->perso->s_fork);
			if (philo->nb_eat > 0)
			{
				if (philo->perso->if_die == 1)
					return (0);
				philo_sleep(philo);
				if (philo->perso->if_die == 1)
					return (0);
				display(philo->name_philo, " is thinking", philo);
			}
		}
	}
	return (0);
}
