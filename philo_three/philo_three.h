/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:37:09 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 11:27:56 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>
# include <signal.h>

# define ERR_ARG "Error: argument\n"

typedef struct		s_philo
{
	int				philo_die;
	int				nb_philo;
	int				np;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				time_die;
	int				nb_eat;
	int				end_eat;
	int				first_eat;
	pid_t			pid;
	int				no_limite;
	int				dead;
	struct timeval	ms_eat;
	struct timeval	ms_sleep;
	struct timeval	ms_think;
	struct timeval	ms_died;
	struct timeval	t_philo;
	struct timeval	start_time;
	sem_t			*s_talk;
	sem_t			*s_talk_die;
	int				if_die;
	int				fork;
}					t_philo;

typedef struct		s_init
{
	int				i;
	int				ret;
	int				*eating;
	int				*fp;
	sem_t			*s_eat;
	sem_t			*s_talk;
	sem_t			*s_die;
	sem_t			*s_fork;
	sem_t			*s_talk_die;
	t_philo			*philo;
}					t_init;

void				*ft_check_thread(void *p_data);
void				ft_thread(pthread_t *td_p, t_philo *philo);
int					proc(t_init *init, int nb_philo);
int					put_error(char *err);
int					ft_atoi(char *nptr);
int					routine(t_philo *philo, t_init *init);
void				*philo_eat(t_philo *philo, t_init *init);
int					philo_sleep(t_philo *philo, t_init *init);
void				*philo_think(t_philo *philo);
long				ft_conv_to_ms(struct timeval philo_time,
									struct timeval start_time);
int					ft_check_die(t_philo *philo);
void				display(int np, char *message, t_philo *philo,
							t_init *init);
void				ft_putnbr(int n);
int					ft_init_var(t_init *init, t_philo *philo,
								char **argv, int i);
int					ft_malloc_struct(int nb_philo, t_init *init);
void				ft_init_sem(int nb_philo, t_init *init);

#endif
