/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:35:51 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 10:00:29 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			philo_sleep(t_philo *philo, t_init *init)
{
	int				i;
	struct timeval	start_sleep;

	i = 0;
	gettimeofday(&start_sleep, NULL);
	usleep(400);
	display(philo->np, " is sleeping", philo, init);
	while (i != 1)
	{
		usleep(10);
		gettimeofday(&philo->ms_sleep, NULL);
		if (ft_conv_to_ms(philo->ms_sleep, start_sleep) >= philo->time_sleep
				|| philo->if_die == 1)
			i = 1;
	}
	return (0);
}
