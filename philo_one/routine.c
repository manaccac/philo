/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:30:14 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/16 10:40:36 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		*routine_no_limit(t_philo *philo)
{
	while (philo->p->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
			return (ft_check_die_two(philo));
		if (philo->p->fork / 2 >= 1)
		{
			if ((philo->p->fp[philo->np - 1] == 1 &&
				philo->p->fp[philo->np] == 1) ||
				(philo->np == 0 && (philo->p->fp[philo->nb_philo - 1] == 1
				&& philo->p->fp[philo->np] == 1)))
			{
				if (routine_two_no_l(philo) == 0)
					return (0);
			}
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
	while (philo->nb_eat > 0 && philo->p->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
			return (ft_check_die_two(philo));
		if (philo->p->fork / 2 >= 1)
		{
			if ((philo->p->fp[philo->np - 1] == 1 &&
				philo->p->fp[philo->np] == 1) ||
				(philo->np == 0 && (philo->p->fp[philo->nb_philo - 1] == 1
				&& philo->p->fp[philo->np] == 1)))
			{
				if (routine_two(philo) == 0)
					return (0);
			}
		}
	}
	return (0);
}
