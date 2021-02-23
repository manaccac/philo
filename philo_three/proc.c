/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:59:47 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 13:47:47 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		proc_two(t_init *init, int nb_philo, int y, int bl)
{
	int status;
	int i;

	status = 0;
	i = 0;
	while (1)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status))
			bl = 1;
		if (WEXITSTATUS(status) == 0)
			y++;
		if (y == nb_philo + 1)
			bl = 1;
		while (bl == 1 && i < nb_philo + 1)
		{
			kill(init->philo[i + 1].pid, 1);
			i++;
		}
		if (i == nb_philo + 1)
			break ;
	}
	return (0);
}

int		proc(t_init *init, int nb_philo)
{
	int i;
	int y;
	int bl;

	i = 0;
	y = 0;
	bl = 0;
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
	return (proc_two(init, nb_philo, y, bl));
}
