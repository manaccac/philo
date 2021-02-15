/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:58:30 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/15 12:04:25 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			*ft_check_die_two(t_philo *philo)
{
	sem_wait(philo->perso->s_die);
	philo->philo_die = 1;
	if (philo->perso->if_die == 0)
	{
		philo->perso->if_die = 1;
		display(philo->name_philo, " died", philo);
	}
	sem_post(philo->perso->s_die);
	return (0);
}

int				take_fork(t_philo *philo)
{
	if (philo->perso->if_die == 1)
		return (0);
	philo->perso->fork -= 2;
	sem_wait(philo->perso->s_fork);
	display(philo->name_philo, " has taken a fork", philo);
	display(philo->name_philo, " has taken a fork", philo);
	if (philo->perso->if_die == 1)
	{
		sem_post(philo->perso->s_fork);
		return (0);
	}
	return (1);
}
