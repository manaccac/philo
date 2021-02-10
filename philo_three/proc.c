/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:59:47 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/10 14:38:23 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		proc(t_philo *philo, int nb_philo)
{
	int i = 0;
	while (i < nb_philo)
	{
		philo[i].pid = fork();
		if (philo->pid < 0)
			return (1);
		else if (philo->pid == 0)
			routine(&philo[i]);
		usleep(100);
		i++;
	}
	return (0);
}
