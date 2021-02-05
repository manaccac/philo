#include "philo_one.h"

void		display(int name_philo, char *message, t_philo *philo)
{
	struct timeval temp;
	gettimeofday(&temp, NULL);
	pthread_mutex_lock(philo->perso->talk);
	ft_putnbr((int)ft_conv_to_ms(temp, philo->start_time));
	write(1, " ", 1);
	ft_putnbr(name_philo);
	ft_putstr(message);
	write(1, "\n", 1);
	pthread_mutex_unlock(philo->perso->talk);
}
