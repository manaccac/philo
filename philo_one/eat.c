#include "philo_one.h"

static void		*philo_eat(t_philo *philo)
{
	dprintf(1, "\nPHILO NUMERO : %d\n", philo->name_philo);
	pthread_mutex_lock(&philo->mutex_philo);
	while (philo->nb_lunch < philo->nb_eat)
	{
		dprintf(1, "Philo numéro %d mange Gucci pour la %d fois\n", philo->name_philo, philo->nb_lunch);
		philo->nb_lunch++;
	}
	if (philo->nb_lunch == philo->nb_eat)
		dprintf(1, "\nPhilo numero %d a fini de manger\n", philo->name_philo);
	pthread_mutex_unlock(&philo->mutex_philo);
	return (0);
}
