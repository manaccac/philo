/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:59:47 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/17 12:46:39 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		proc(t_init *init, int nb_philo)
{
	int i = 0;
	int status = 0;
	while (i < nb_philo)
	{
		init->philo[i].pid = fork();
		if (init->philo[i].pid == -1)
			exit(1);
		if (init->philo[i].pid == 0)
		{
			routine(&init->philo[i], init);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		waitpid(init->philo[i].pid, &status, 0);
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		kill(init->philo[i].pid, 15);
		i++;
	}
	return (0);
}
