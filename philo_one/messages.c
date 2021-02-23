/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:04:58 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/16 09:34:09 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		display(int name_philo, char *message, t_philo *philo)
{
	struct timeval temp;

	pthread_mutex_lock(philo->p->talk);
	if (philo->philo_die == 1)
	{
		gettimeofday(&temp, NULL);
		printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time),
				name_philo + 1, message);
		pthread_mutex_unlock(philo->p->talk);
		return ;
	}
	else if (philo->p->if_die == 1)
	{
		pthread_mutex_unlock(philo->p->talk);
		return ;
	}
	gettimeofday(&temp, NULL);
	printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time),
				name_philo + 1, message);
	pthread_mutex_unlock(philo->p->talk);
}
