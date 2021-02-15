#include "philo_three.h"

void		display(int np, char *message, t_philo *philo)
{
	struct timeval temp;
	sem_wait(philo->p->s_talk);
	if (philo->philo_die == 1)
	{
		gettimeofday(&temp, NULL);
		printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time), np + 1, message);
		sem_post(philo->p->s_talk);
		return ;
	}
	else if (philo->p->if_die == 1)
	{
		sem_post(philo->p->s_talk);
		return ;
	}
	gettimeofday(&temp, NULL);
	printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time), np + 1, message);
	sem_post(philo->p->s_talk);
}
