/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:51:07 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/15 11:51:21 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		display(int name_philo, char *message, t_philo *philo)
{
	struct timeval temp;

	sem_wait(philo->perso->s_talk);
	if (philo->philo_die == 1)
	{
		gettimeofday(&temp, NULL);
		printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time),
				name_philo + 1, message);
		sem_post(philo->perso->s_talk);
		return ;
	}
	else if (philo->perso->if_die == 1)
	{
		sem_post(philo->perso->s_talk);
		return ;
	}
	gettimeofday(&temp, NULL);
	printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time),
			name_philo + 1, message);
	sem_post(philo->perso->s_talk);
}
