/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:59:47 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/19 09:59:06 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		proc(t_init *init, int nb_philo)
{
	init->i = 0;
	int i = 0;
	int status = 0;

	while (i < nb_philo + 1)
	{
		init->philo[i + 1].pid = fork();
		if (init->philo[i + 1].pid == -1)
			exit(1);
		if (init->philo[i + 1].pid == 0)
		{
			init->i++;
			if (routine(&init->philo[i], init) == 0)
				exit(0);
			else
				exit(1);
		}
		i++;
	}
	i = 0;
	int y = 0;
	int bl = 0;
	while (1)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status))
			bl = 1;
		if (WEXITSTATUS(status) == 0)
			y++;
		if (y == nb_philo)
			bl = 1;
		i = 0;
		while (bl && i < nb_philo + 1)
		{
			kill(init->philo[i + 1].pid, 1);
			i++;
		}
		if (i == nb_philo + 1)
			break;
	}
	return (0);
}
