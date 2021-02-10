#include "philo_one.h"

void		display(int name_philo, char *message, t_philo *philo)
{
	struct timeval temp;
	pthread_mutex_lock(philo->perso->talk);
	if (philo->philo_die == 1)
	{
		gettimeofday(&temp, NULL);
		printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time), name_philo + 1, message);
		pthread_mutex_unlock(philo->perso->talk);
		return ;
	}
	else if (philo->perso->if_die == 1)
	{
		pthread_mutex_unlock(philo->perso->talk);
		return ;
	}
	gettimeofday(&temp, NULL);
	printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time), name_philo + 1, message);
	pthread_mutex_unlock(philo->perso->talk);
}
