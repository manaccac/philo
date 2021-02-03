/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:47:17 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/03 12:10:24 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


typedef struct		s_philo
{
	int nb_philo;
	int name_philo;
	int time_eat;
	int time_sleep;
	int time_die;
	int nb_eat;
	int nb_lunch;
	pthread_mutex_t mutex_philo;
	pthread_mutex_t mt_eat;
	// Time
	long ms_eat;
	long ms_sleep;
	long ms_think;
	long ms_died;
	struct timeval t_philo;
	struct timeval start_time;
}					t_philo;

int		ft_atoi(char *nptr);
void	ft_putstr(char *str);
void	*routine(void *p_data);
void	*philo_eat(t_philo *philo);