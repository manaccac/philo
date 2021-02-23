/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:48:32 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 13:42:25 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int		routine_two(t_philo *philo, t_init *init)
{
	while (philo->no_limite == 1 && philo->if_die == 0)
	{
		usleep(10);
		sem_wait(init->s_fork);
		if (philo->if_die == 1)
			return (1);
		display(philo->np, " has taken a fork", philo, init);
		display(philo->np, " has taken a fork", philo, init);
		if (philo->if_die == 1)
			return (1);
		philo_eat(philo, init);
		sem_post(init->s_fork);
		philo_sleep(philo, init);
		if (philo->if_die == 1)
			return (1);
		display(philo->np, " is thinking", philo, init);
		if (philo->if_die == 1)
			return (1);
	}
	return (0);
}

static int		routine_three(t_philo *philo, t_init *init)
{
	sem_wait(init->s_fork);
	if (philo->if_die == 1)
		return (1);
	display(philo->np, " has taken a fork", philo, init);
	display(philo->np, " has taken a fork", philo, init);
	if (philo->if_die == 1)
		return (1);
	philo_eat(philo, init);
	sem_post(init->s_fork);
	if (philo->nb_eat > 0)
	{
		philo_sleep(philo, init);
		if (philo->if_die == 1)
			return (1);
		display(philo->np, " is thinking", philo, init);
	}
	if (philo->if_die == 1)
		return (1);
	return (0);
}

int				routine(t_philo *philo, t_init *init)
{
	pthread_t			td_p;
	int					ret;

	ret = 0;
	ret = pthread_create(&td_p, NULL, ft_check_thread, (void *)philo);
	pthread_detach(td_p);
	if (philo->no_limite == 1)
		return (routine_two(philo, init));
	while (philo->no_limite == 0 && philo->nb_eat > 0 && philo->if_die == 0)
	{
		usleep(10);
		if (routine_three(philo, init) == 1)
			return (1);
	}
	return (0);
}
