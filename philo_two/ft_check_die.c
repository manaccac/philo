/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:40:23 by manaccac          #+#    #+#             */
/*   Updated: 2021/02/18 09:18:56 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		ft_check_die(t_philo *philo)
{
	struct timeval temp_dead;

	gettimeofday(&temp_dead, NULL);
	if (ft_conv_to_ms(temp_dead, philo->ms_died) >= philo->time_die)
		return (1);
	else
		return (0);
}
