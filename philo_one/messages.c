#include "philo_one.h"

void		display(int name_philo, char *message, t_philo *philo)
{
	struct timeval temp;
	pthread_mutex_lock(philo->perso->talk);
	gettimeofday(&temp, NULL);
	printf("%d %d%s\n", (int)ft_conv_to_ms(temp, philo->start_time), name_philo, message);
	pthread_mutex_unlock(philo->perso->talk);
}
