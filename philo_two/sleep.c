/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 19:33:17 by juan              #+#    #+#             */
/*   Updated: 2021/02/05 19:33:58 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*philo_sleep(t_philo *philo)
{
	int				i;
	struct timeval	start_sleep;

	i = 0;
	gettimeofday(&start_sleep, NULL);
	display(philo->name_philo, " is sleeping", philo);
	while (i != 1)
	{
		gettimeofday(&philo->ms_sleep, NULL);
		if (ft_conv_to_ms(philo->ms_sleep, start_sleep) >= philo->time_sleep
							|| philo->perso->if_die == 1)
			i = 1;
	}
	return (0);
}
