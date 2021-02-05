/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 09:17:15 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/04 10: by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct		s_philo
{
	int	satiate;
	int philo_die;
	int nb_philo;
	int name_philo;
	int time_eat;
	int time_sleep;
	int	time_think;
	int time_die;
	int nb_eat;
	int end_eat;
	int first_eat;
	//pas de limite de repas
	int	no_limite;
	//mort du philo
	int dead;
	pthread_mutex_t mt_eat;
	// Time
	struct timeval ms_eat;
	struct timeval ms_sleep;
	struct timeval ms_think;
	struct timeval ms_died;
	//
	struct timeval t_philo;
	struct timeval start_time;
	struct s_perso *perso;
}					t_philo;

typedef struct		s_perso
{
	int *eating;
	int	start;
	int if_die;
	int fork;
	int *fork_perso;
	t_philo *philo;
	pthread_mutex_t *talk;
	pthread_mutex_t *die;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
}					t_perso;

typedef struct		s_init
{
	t_philo			*philo;
	t_perso			*perso;
}					t_init;


int		ft_atoi(char *nptr);
void	ft_putstr(char *str);
void	*routine(void *p_data);
void	*philo_eat(t_philo *philo);
void	*philo_sleep(t_philo *philo);
void	*philo_think(t_philo *philo);
long	ft_conv_to_ms(struct timeval philo_time, struct timeval start_time);
int		ft_check_die(t_philo *philo);
void	display(int name_philo, char *message, t_philo *philo);
void	ft_putnbr(int n);
int		ft_init_var(int nb_philo, t_philo *philo, char **argv, int i, struct timeval start_time);
int		ft_malloc_struct(int nb_philo, t_init *init);
