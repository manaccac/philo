/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:40:23 by manaccac          #+#    #+#             */
/*   Updated: 2021/02/15 09:38:59 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_check_die(t_philo *philo)
{
	struct timeval temp_dead;

	gettimeofday(&temp_dead, NULL);
	if (ft_conv_to_ms(temp_dead, philo->ms_died) > philo->time_die)
		return (1);
	else
		return (0);
}
