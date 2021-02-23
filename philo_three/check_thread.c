/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:04:52 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 08:47:58 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			*ft_check_thread(void *p_data)
{
	t_philo *philo;

	philo = p_data;
	//printf("philo =  %d\n", philo->np);
	usleep(1000);
	while (1)
	{
		if (ft_check_die(philo) == 1)
		{
			struct timeval temp_dead;
			gettimeofday(&temp_dead, NULL);
			philo->philo_die = 1;
			if (philo->if_die == 0)
			{
				sem_wait(philo->s_talk_die);
				printf("%d %d%s\n", (int)ft_conv_to_ms(temp_dead, philo->start_time), philo->np + 1, " is died");
				philo->if_die = 1;
			}
			exit (1);
		}
		usleep(100);
	}
	return (0);
}
