/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:57:52 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 09:58:43 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		display(int np, char *message, t_philo *philo, t_init *init)
{
	struct timeval temp;

	if (philo->if_die == 1)
		;
	else if (ft_check_die(philo) == 1)
		philo->if_die = 1;
	else
	{
		usleep(100);
		sem_wait(init->s_talk);
		sem_wait(philo->s_talk_die);
		gettimeofday(&temp, NULL);
		printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time),
				np + 1, message);
		sem_post(philo->s_talk_die);
		sem_post(init->s_talk);
	}
}
