#include "philo_one.h"

void		display(int name_philo, char *message, t_philo *philo)
{
	pthread_mutex_lock(philo->perso->talk);
	ft_putnbr(name_philo);
	ft_putstr(message);
	write(1, "\n", 1);
	pthread_mutex_unlock(philo->perso->talk);
}