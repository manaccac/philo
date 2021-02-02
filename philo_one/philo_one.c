/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:43:42 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/02 15:41:41 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_atoi(char *nptr)
{
	int				i;
	int				a;
	long int		res;

	res = 0;
	a = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		a = -a;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * a);
}

static void		*philo_eat(void *p_data)
{
	t_philo *philo = p_data;
	dprintf(1, "\nPHILO NUMERO : %d\n", philo->name_philo);
	// dprintf(1, "\nNB_EAT DE PHILO NUMERO %d: %d\n", philo->nb_lunch, philo->name_philo);
	// pthread_mutex_lock (&philo.mutex_stock);
	pthread_mutex_lock(&philo->mutex_philo);
	while (philo->nb_lunch < philo->nb_eat)
	{
		dprintf(1, "Philo numéro %d mange Gucci pour la %d fois\n", philo->name_philo, philo->nb_lunch);
		philo->nb_lunch++;
	}
	// dprintf(1, "\nNB_LUNCH DE PHILO NUMERO %d: %d\n", philo->nb_lunch, philo->name_philo);
	if (philo->nb_lunch == philo->nb_eat)
		dprintf(1, "\nPhilo numero %d a fini de manger\n", philo->name_philo);
	pthread_mutex_unlock(&philo->mutex_philo);
	return (0);
}

int			main(int argc, char **argv)
{
	t_philo *philo;
	int nb_philo = ft_atoi(argv[1]);
	int i = 0;
	if (!(philo = malloc(sizeof(philo) * nb_philo)))
		return (0);
	while (i < nb_philo)
	{
		philo[i].nb_lunch = 0;
		philo[i].nb_philo = nb_philo;
		philo[i].time_die = ft_atoi(argv[2]);
		philo[i].time_eat = ft_atoi(argv[3]);
		philo[i].time_sleep = ft_atoi(argv[4]);
		philo[i].name_philo = i;
		if (argc == 6)
			philo[i].nb_eat = ft_atoi(argv[5]);
		i++;
	}
	
	pthread_t thread_philo[nb_philo];
	int ret = 0;
	// dprintf(1, "nb philo = %d\ntime_die = %d\ntime_eat = %d\ntime_sleep = %d\nnb_eat = %d\n", philo.nb_philo, philo.time_die, philo.time_eat, philo.time_sleep, philo.nb_eat);
	// dprintf(1, "Creation des philos\n");
	i = 0;
	while (i < nb_philo)
	{
		ret = pthread_create(&thread_philo[i], NULL, philo_eat, &philo[i]);
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_join(thread_philo[i], NULL);
		i++;
	}
	return (ret);
}
