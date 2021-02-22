/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:35:51 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/22 08:51:14 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			philo_sleep(t_philo *philo, t_init *init)
{
	int i;
	i = 0;
	struct timeval start_sleep;
	gettimeofday(&start_sleep, NULL);
	usleep(400);
	display(philo->np, " is sleeping", philo, init);
	while (i != 1)
	{
		usleep(10);
		gettimeofday(&philo->ms_sleep, NULL);
		if (ft_conv_to_ms(philo->ms_sleep, start_sleep) >= philo->time_sleep || philo->if_die == 1)
			i = 1;
	}
	return (0);
}
