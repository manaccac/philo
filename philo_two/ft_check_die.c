/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:40:23 by manaccac          #+#    #+#             */
/*   Updated: 2021/02/07 14:11:18 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_check_die(t_philo *philo)
{
	struct timeval temp_dead;

	gettimeofday(&temp_dead, NULL);
	if (ft_conv_to_ms(temp_dead, philo->ms_died) > philo->time_die)
		return (1);
	else
		return (0);
}

 void	*ft_return_die(t_philo *philo)
{
	philo->philo_die = 1;
	if (philo->perso->if_die == 0)
	{
		philo->perso->if_die = 1;
		display(philo->name_philo, " died", philo);
	}
	pthread_mutex_unlock(philo->perso->die);
	return (0);
}
