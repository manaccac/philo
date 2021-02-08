/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_to_ms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:45:12 by manaccac          #+#    #+#             */
/*   Updated: 2021/02/03 13:34:11 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	ft_conv_to_ms(struct timeval philo_time, struct timeval start_time)
{
	long sec;
	long micro;
	long mili;

	sec = philo_time.tv_sec - start_time.tv_sec;
	micro = philo_time.tv_usec - start_time.tv_usec;
	mili = micro * 0.001 + sec * 1000;
	return (mili);
}
