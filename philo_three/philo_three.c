/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:52:35 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 12:37:39 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int			check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (put_error(ERR_ARG));
	if (argv[1][0] == '-')
		return (put_error(ERR_ARG));
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		return (put_error(ERR_ARG));
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 ||
		ft_atoi(argv[4]) < 60)
		return (put_error(ERR_ARG));
	return (1);
}

static void			ft_free(t_init *init)
{
	free(init->philo);
}

int					main(int argc, char **argv)
{
	t_init			init;
	struct timeval	start_time;
	int				nb_philo;
	int				i;

	if (check_arg(argc, argv) == 0)
		return (0);
	nb_philo = ft_atoi(argv[1]);
	i = 0;
	if (ft_malloc_struct(nb_philo, &init) == -1)
		return (-1);
	gettimeofday(&start_time, NULL);
	while (i < nb_philo)
	{
		init.philo[i].start_time = start_time;
		ft_init_var(&init, init.philo, argv, i);
		gettimeofday(&init.philo[i].ms_died, NULL);
		i++;
	}
	ft_init_sem(nb_philo, &init);
	proc(&init, nb_philo);
	ft_free(&init);
	return (0);
}
