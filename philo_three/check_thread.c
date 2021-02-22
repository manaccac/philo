/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:04:52 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/22 07:57:29 by manaccac         ###   ########lyon.fr   */
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
				philo->if_die = 1;
				// dprintf(1, "{%ld}\n", ft_conv_to_ms(temp_dead, philo->start_time));
				// dprintf(1, "DIE\n");
				// dprintf(1, "nb philo die = %d\n", philo->np + 1);
				printf("%d %d%s\n", (int)ft_conv_to_ms(temp_dead, philo->start_time), philo->np + 1, " is died");
			}
			exit (1);
		}
		usleep(100);
	}
	return (0);
}
