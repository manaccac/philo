/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:59:47 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/18 12:40:54 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		proc(t_init *init, int nb_philo)
{
	int i = 0;
	int status = 0;

	while (i < nb_philo + 1)
	{
		init->philo[i + 1].pid = fork();
		if (init->philo[i + 1].pid == -1)
			exit(1);
		if (init->philo[i + 1].pid == 0)
		{
			if (routine(&init->philo[i], init) == 0)
				exit(0);
			else
				exit(1);
		}
		i++;
	}
	int u = 0;
	int y = 0;
	int bl = 0;
	while (1)
	{
		i = 0;
		waitpid(init->philo[u].pid, &status, 0);
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
