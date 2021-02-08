/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 19:34:49 by juan              #+#    #+#             */
/*   Updated: 2021/02/05 19:34:59 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*philo_think(t_philo *philo)
{
	int				i;
	struct timeval	start_think;

	i = 0;
	gettimeofday(&start_think, NULL);
	display(philo->name_philo, " is thinking", philo);
	return (0);
}
