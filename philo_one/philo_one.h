/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:27:35 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/16 10:42:41 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define ERR_ARG "Error: argument\n"

typedef struct		s_philo
{
	int				satiate;
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
	int				no_limite;
	int				dead;
	pthread_mutex_t	mt_eat;
	struct timeval	ms_eat;
	struct timeval	ms_sleep;
	struct timeval	ms_think;
	struct timeval	ms_died;
	struct timeval	t_philo;
	struct timeval	start_time;
	struct s_perso	*p;
}					t_philo;

typedef struct		s_perso
{
	int				*eating;
	int				if_die;
	int				fork;
	int				*fp;
	t_philo			*philo;
	pthread_mutex_t *talk;
	pthread_mutex_t *die;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
}					t_perso;

typedef struct		s_init
{
	int				ret;
	t_philo			*philo;
	t_perso			*p;
}					t_init;

int					put_error(char *err);
int					ft_atoi(char *nptr);
void				ft_putstr(char *str);
void				*routine(void *p_data);
void				*philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				*philo_think(t_philo *philo);
long				ft_conv_to_ms(struct timeval philo_time,
						struct timeval start_time);
int					ft_check_die(t_philo *philo);
void				display(int np, char *message, t_philo *philo);
void				ft_putnbr(int n);
int					ft_init_var(int nb_philo, t_philo *philo,
								char **argv, int i);
int					ft_malloc_struct(int nb_philo, t_init *init);
void				ft_init_two(int nb_p, t_init *init, char **argv,
								struct timeval	st);
void				*ft_check_die_two(t_philo *philo);
int					take_fork(t_philo *philo);
int					return_fork(t_philo *philo);
int					routine_two(t_philo *philo);
void				ft_init_two(int nb_p, t_init *init, char **argv,
								struct timeval st);
int					routine_two_no_l(t_philo *philo);

#endif
