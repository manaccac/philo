/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:47:17 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/02 15:39:41 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// typedef struct		s_global
// {
// 	int nb_philo;
// 	t_philo *philo;
// }					t_global;

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
}					t_philo;

int		ft_atoi(char *nptr);