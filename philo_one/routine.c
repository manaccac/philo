#include "philo_one.h"

static void		*routine(void *p_data)
{
	t_philo *philo = p_data;
	philo_eat(philo);
	return (0);
}
