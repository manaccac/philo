/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:49:41 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 13:39:01 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int		check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (put_error(ERR_ARG));
	if (argv[1][0] == '-')
		return (put_error(ERR_ARG));
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		return (put_error(ERR_ARG));
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (put_error(ERR_ARG));
	return (1);
}

static void		ft_free(t_init *init)
{
	free(init->perso->eating);
	free(init->perso->fork_perso);
	free(init->philo);
	free(init->perso);
}

void			ft_thread(int nb_philo, pthread_t td_p[nb_philo], t_init *init)
{
	int i;

	i = 0;
	while (i < nb_philo)
	{
		init->ret = pthread_create(&td_p[i],
									NULL, routine, &init->philo[i]);
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_join(td_p[i], NULL);
		i++;
	}
}

static int		return_nb_philo(int argc, char **argv)
{
	int ret;

	if (argc < 5)
		return (0);
	if (argv[1][0] != '-')
	{
		ret = ft_atoi(argv[1]);
		return (ret);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_init			init;
	struct timeval	start_time;
	int				nb_philo;
	int				i;
	pthread_t		thread_philo[return_nb_philo(argc, argv)];

	if (check_arg(argc, argv) == 0)
		return (0);
	nb_philo = ft_atoi(argv[1]);
	i = 0;
	if (ft_malloc_struct(nb_philo, &init) == -1)
		return (-1);
	gettimeofday(&start_time, NULL);
	ft_init_two(nb_philo, &init, argv, start_time);
	init.ret = 0;
	ft_thread(nb_philo, thread_philo, &init);
	ft_free(&init);
	return (init.ret);
}
