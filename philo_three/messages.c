#include "philo_three.h"

void		display(int np, char *message, t_philo *philo, t_init *init)
{
	struct timeval temp;

	if (philo->philo_die == 1)
	{
		sem_wait(init->s_die);
		gettimeofday(&temp, NULL);
		printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time), np + 1, message);
		return ;
	}
	// sem_wait(init->s_prio);
	// sem_post(init->s_prio);
	sem_wait(init->s_talk);
	gettimeofday(&temp, NULL);
	printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time), np + 1, message);
	sem_post(init->s_talk);
}
