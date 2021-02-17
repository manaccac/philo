/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:02:44 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/17 12:44:15 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		*philo_eat_no_limite(t_philo *philo, int i)
{
	struct timeval	start_eat;

	gettimeofday(&start_eat, NULL);
	while (i != 1)
	{
		gettimeofday(&philo->ms_eat, NULL);
		if (ft_conv_to_ms(philo->ms_eat, start_eat) >= philo->time_eat
							|| philo->p->if_die == 1)
			i = 1;
	}
	return (0);
}

void			*philo_eat(t_philo *philo)
{
	int				i;
	struct timeval	start_eat;

	i = 0;
	display(philo->np, " is eating", philo);
	gettimeofday(&philo->ms_died, NULL);
	if (philo->no_limite == 1)
		return (philo_eat_no_limite(philo, i));
	if (philo->nb_eat >= 0)
	{
		gettimeofday(&start_eat, NULL);
		while (i != 1)
		{
			gettimeofday(&philo->ms_eat, NULL);
			if (ft_conv_to_ms(philo->ms_eat, start_eat) >=
				philo->time_eat || philo->p->if_die == 1)
				i = 1;
		}
		philo->nb_eat--;
	}
	if (philo->nb_eat == 0)
		philo->end_eat = 1;
	return (0);
}
