/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:04:52 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/19 07:56:54 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			*ft_check_thread(void *p_data)
{
	t_philo *philo;

	philo = p_data;
	printf("philo =  %d\n", philo->np);
	// while (1)
	// {
	sem_wait(philo->s_management);
	if (philo->reload == 1)
	{
		dprintf(1, "reload = %d\n", philo->reload);
		gettimeofday(&philo->ms_died, NULL);
		philo->reload = 0;
	}
	if (ft_check_die(philo) == 1)
	{
		sem_wait(philo->s_talk);
		philo->philo_die = 1;
		if (philo->if_die == 0)
		{
			philo->if_die = 1;
			// display(philo->np, " died", philo, init);
		}
		return (0);
	}
	sem_post(philo->s_management);
	usleep(50);
	// }
	return (0);
}
