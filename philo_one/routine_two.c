/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:19:24 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 10:02:18 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			*ft_check_die_two(t_philo *philo)
{
	pthread_mutex_lock(philo->p->die);
	philo->philo_die = 1;
	if (philo->p->if_die == 0)
	{
		philo->p->if_die = 1;
		display(philo->np, " died", philo);
	}
	pthread_mutex_unlock(philo->p->die);
	return (0);
}

int				take_fork(t_philo *philo)
{
	philo->p->fp[philo->np] = 0;
	if (philo->np != 0)
		philo->p->fp[philo->np - 1] = 0;
	else
		philo->p->fp[philo->nb_philo - 1] = 0;
	if (philo->p->if_die == 1)
		return (0);
	pthread_mutex_lock(&philo->p->l_fork[philo->np]);
	display(philo->np, " has taken a fork", philo);
	philo->p->fork -= 1;
	pthread_mutex_lock(&philo->p->r_fork[philo->np]);
	display(philo->np, " has taken a fork", philo);
	philo->p->fork -= 1;
	if (philo->p->if_die == 1)
	{
		pthread_mutex_unlock(&philo->p->l_fork[philo->np]);
		pthread_mutex_unlock(&philo->p->r_fork[philo->np]);
		return (0);
	}
	return (1);
}

int				return_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->p->l_fork[philo->np]);
	pthread_mutex_unlock(&philo->p->r_fork[philo->np]);
	philo->p->fork += 2;
	philo->p->fp[philo->np] = 1;
	if (philo->np != 0)
		philo->p->fp[philo->np - 1] = 1;
	else
		philo->p->fp[philo->nb_philo - 1] = 1;
	if (philo->p->if_die == 1)
		return (0);
	return (1);
}

int				routine_two(t_philo *philo)
{
	if (philo->p->fork / 2 >= 1)
	{
		if (take_fork(philo) == 0)
			return (0);
		philo_eat(philo);
		if (return_fork(philo) == 0)
			return (0);
		if (philo->nb_eat > 0)
		{
			philo_sleep(philo);
			if (philo->p->if_die == 1)
				return (0);
			display(philo->np, " is thinking", philo);
		}
	}
	return (1);
}

int				routine_two_no_l(t_philo *philo)
{
	if (philo->p->fork / 2 >= 1)
	{
		if (take_fork(philo) == 0)
			return (0);
		philo_eat(philo);
		if (return_fork(philo) == 0)
			return (0);
		philo_sleep(philo);
		if (philo->p->if_die == 1)
			return (0);
		display(philo->np, " is thinking", philo);
	}
	return (1);
}
