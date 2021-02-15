/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:45:17 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/15 11:30:14 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*routine_no_limit(t_philo *philo)
{
	while (philo->p->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
			return (ft_check_die_two(philo));
		else if (philo->p->fork / 2 >= 1)
		{
			if ((philo->p->fp[philo->np - 1] == 1 &&
					philo->p->fp[philo->np] == 1) ||
				(philo->np == 0 &&
				(philo->p->fp[philo->nb_philo - 1] == 1
				&& philo->p->fp[philo->np] == 1)))
			{
				if (philo->p->fork / 2 >= 1)
				{
					if (routine_two(philo) == 0)
						return (0);
				}
			}
		}
	}
	return (0);
}

void		*routine(void *p_data)
{
	t_philo *ph;

	ph = p_data;
	if (ph->no_limite == 1)
		return (routine_no_limit(ph));
	while (ph->nb_eat > 0 && ph->p->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(ph) == 1)
			return (ft_check_die_two(ph));
		else if (ph->p->fork / 2 >= 1)
		{
			if ((ph->p->fp[ph->np - 1] == 1 && ph->p->fp[ph->np] == 1) ||
				(ph->np == 0 && (ph->p->fp[ph->nb_philo - 1] == 1 &&
				ph->p->fp[ph->np] == 1)))
			{
				if (ph->p->fork / 2 >= 1)
				{
					if (routine_two(ph) == 0)
						return (0);
				}
			}
		}
	}
	return (0);
}
