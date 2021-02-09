#include "philo_one.h"

void		*philo_think(t_philo *philo)
{
	int i;
	i = 0;
	struct timeval start_think;
	gettimeofday(&start_think, NULL);
	display(philo->name_philo, " is thinking", philo);
	return (0);
}
