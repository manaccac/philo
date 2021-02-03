/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:47:17 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/03 12:56:49 by manaccac         ###   ########lyon.fr   */
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
	pthread_mutex_t mutex_philo;
	pthread_mutex_t mt_eat;
	// Time
	struct timeval ms_eat;
	struct timeval ms_sleep;
	struct timeval ms_think;
	struct timeval ms_died;
	//
	struct timeval t_philo;
	struct timeval start_time;
}					t_philo;

int		ft_atoi(char *nptr);
void	ft_putstr(char *str);
void	*routine(void *p_data);
void	*philo_eat(t_philo *philo);
long	ft_conv_to_ms(struct timeval philo_time, struct timeval start_time);
