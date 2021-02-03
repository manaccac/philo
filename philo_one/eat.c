#include "philo_one.h"

void		*philo_eat(t_philo *philo)
{
	dprintf(1, "\nPHILO NUMERO : %d\n", philo->name_philo);
	pthread_mutex_lock(&philo->mutex_philo);
	if (philo->nb_eat)
	{
		while (philo->nb_eat != 0)
		{
			dprintf(1, "Philo numéro %d mange Gucci il lui reste %d repas\n", philo->name_philo, philo->nb_eat);
			philo->nb_eat--;
		}
		if (philo->nb_eat == 0)
			dprintf(1, "\nPhilo numero %d a fini de manger\n", philo->name_philo);
	}
	pthread_mutex_unlock(&philo->mutex_philo);
	return (0);
}
