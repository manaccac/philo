/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:39:53 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/15 11:40:40 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void		*philo_eat_no_limite(t_philo *philo, int i)
{
	struct timeval	start_eat;

	gettimeofday(&start_eat, NULL);
	while (i != 1)
	{
		gettimeofday(&philo->ms_eat, NULL);
		if (ft_conv_to_ms(philo->ms_eat, start_eat) >= philo->time_eat
							|| philo->perso->if_die == 1)
			i = 1;
	}
	return (0);
}

void			*philo_eat(t_philo *philo)
{
	int				i;
	struct timeval	start_eat;

	i = 0;
	gettimeofday(&philo->ms_died, NULL);
	display(philo->name_philo, " is eating", philo);
	if (philo->no_limite == 1)
		return (philo_eat_no_limite(philo, i));
	else if (philo->nb_eat >= 0)
	{
		gettimeofday(&start_eat, NULL);
		while (i != 1)
		{
			gettimeofday(&philo->ms_eat, NULL);
			if (ft_conv_to_ms(philo->ms_eat, start_eat) >= philo->time_eat
								|| philo->perso->if_die == 1)
				i = 1;
		}
		philo->nb_eat--;
	}
	if (philo->nb_eat == 0)
		philo->end_eat = 1;
	return (0);
}
