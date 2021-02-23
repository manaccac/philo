/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:16:20 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 09:37:42 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		philo_sleep(t_philo *philo)
{
	int				i;
	struct timeval	start_sleep;

	i = 0;
	gettimeofday(&start_sleep, NULL);
	display(philo->np, " is sleeping", philo);
	while (i != 1)
	{
		if (ft_check_die(philo) == 1)
		{
			pthread_mutex_lock(philo->p->die);
			philo->philo_die = 1;
			if (philo->p->if_die == 0)
			{
				philo->p->if_die = 1;
				display(philo->np, " died", philo);
			}
			pthread_mutex_unlock(philo->p->die);
			return ;
		}
		gettimeofday(&philo->ms_sleep, NULL);
		if (ft_conv_to_ms(philo->ms_sleep, start_sleep) >=
				philo->time_sleep || philo->p->if_die == 1)
			i = 1;
	}
}
