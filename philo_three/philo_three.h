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
#include <sys/types.h>
#include <semaphore.h>
#include <signal.h>

#define ERR_ARG "Error: argument\n"

typedef struct		s_philo
{
	int	satiate;
	int philo_die;
	int nb_philo;
	int np;
	int time_eat;
	int time_sleep;
	int	time_think;
	int time_die;
	int nb_eat;
	int end_eat;
	int first_eat;
	pid_t pid;
	//pas de limite de repas
	int	no_limite;
	//mort du philo
	int dead;
	// Time
	struct timeval ms_eat;
	struct timeval ms_sleep;
	struct timeval ms_think;
	struct timeval ms_died;
	//
	struct timeval t_philo;
	struct timeval start_time;
	sem_t *s_talk;
	sem_t *s_management;
	int if_die;
	int fork;
	int reload;
}					t_philo;

typedef struct		s_init
{
	int i;
	int ret;
	int *eating;
	int *fp;
	sem_t *s_eat;
	sem_t *s_prio;
	sem_t *s_talk;
	sem_t *s_die;
	sem_t *s_fork;
	sem_t *s_management;
	t_philo		*philo;
}					t_init;

void	*ft_check_thread(void *p_data);
void	ft_thread(pthread_t *td_p, t_philo *philo);
int		proc(t_init *init, int nb_philo);
int		put_error(char *err);
int		ft_atoi(char *nptr);
void	ft_putstr(char *str);
int		routine(t_philo *philo, t_init *init);
void	*philo_eat(t_philo *philo, t_init *init);
int		philo_sleep(t_philo *philo, t_init *init);
void	*philo_think(t_philo *philo);
long	ft_conv_to_ms(struct timeval philo_time, struct timeval start_time);
int		ft_check_die(t_philo *philo);
void	display(int np, char *message, t_philo *philo, t_init *init);
void	ft_putnbr(int n);
int		ft_init_var(t_init *init, int nb_philo, t_philo *philo, char **argv, int i, struct timeval start_time);
int		ft_malloc_struct(int nb_philo, t_init *init);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int		ft_strlen(char *str);
char	*ft_itoa(int n);