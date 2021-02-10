/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:52:35 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/10 14:27:56 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int			check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (put_error(ERR_ARG));
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0)
		return (put_error(ERR_ARG));
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (put_error(ERR_ARG));
	return (1);
}

static void			ft_free(t_init *init)
{
    free(init->perso->eating);
	free(init->perso->fork_perso);
	free(init->philo);
	free(init->perso);
}

int				main(int argc, char **argv)
{
	t_init init;
	struct timeval start_time;
	int nb_philo;
	int i;

	if (check_arg(argc, argv) == 0)
		return (0);
	nb_philo = ft_atoi(argv[1]);
	i = 0;
	if (nb_philo <= 1)
	{
		ft_putstr("Le nombre de philo doit être supérieur a 1");
		return (-1);
	}
	if (ft_malloc_struct(nb_philo, &init) == -1)
		return (-1);
	gettimeofday(&start_time, NULL);
	while (i < nb_philo)
	{
		ft_init_var(nb_philo, init.philo, argv, i, start_time);
		gettimeofday(&init.philo[i].ms_died, NULL);
		init.philo[i].perso = init.perso;
		init.philo[i].perso->fork_perso[i] = 1;
		init.philo[i].perso->eating[i] = 0;
		i++;
	}
	// pthread_t thread_philo[nb_philo];
	sem_unlink("/fork");
	sem_unlink("/die");
	sem_unlink("/talk");
	init.perso->s_talk = sem_open("/talk", O_CREAT | O_EXCL, S_IRWXU, 1);
	init.perso->s_die = sem_open("/die", O_CREAT | O_EXCL, S_IRWXU, 1);
	init.perso->s_fork = sem_open("/fork", O_CREAT | O_EXCL, S_IRWXU, nb_philo + 1);
	proc(init.philo, nb_philo);
	ft_free(&init);
	return (0);
}
