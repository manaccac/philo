/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:52:35 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/17 10:22:18 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int			check_arg(int argc, char **argv)
{
	if (argv[1][0] == '-')
		return (put_error(ERR_ARG));
	if (argc < 5 || argc > 6)
		return (put_error(ERR_ARG));
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		return (put_error(ERR_ARG));
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (put_error(ERR_ARG));
	return (1);
}

static void			ft_free(t_init *init)
{
    // free(init->eating);
	// free(init->fp);
	free(init->philo);
	// free(init->);
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
	if (ft_malloc_struct(nb_philo, &init) == -1)
		return (-1);
	gettimeofday(&start_time, NULL);
	while (i < nb_philo)
	{
		ft_init_var(&init, nb_philo, init.philo, argv, i, start_time);
		gettimeofday(&init.philo[i].ms_died, NULL);
		// init.philo[i].p = init.perso;
		// init.philo[i].p->fp[i] = 1;
		// init.philo[i].p->eating[i] = 0;
		i++;
	}
	sem_unlink("/fork");
	sem_unlink("/die");
	sem_unlink("/talk");
	sem_unlink("/eat");
	sem_unlink("/prio");
	init.s_talk = sem_open("/talk", O_CREAT | O_EXCL, S_IRWXU, 1);
	init.s_talk = sem_open("/prio", O_CREAT | O_EXCL, S_IRWXU, 1);
	init.s_eat = sem_open("/eat", O_CREAT | O_EXCL, S_IRWXU, nb_philo / 2);
	init.s_die = sem_open("/die", O_CREAT | O_EXCL, S_IRWXU, 1);
	init.s_fork = sem_open("/fork", O_CREAT | O_EXCL, S_IRWXU, nb_philo / 2);
	proc(&init, nb_philo);
	ft_free(&init);
	return (0);
}
