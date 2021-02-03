#include "philo_one.h"

void		*philo_think(t_philo *philo)
{
	int i;
	// dprintf(1, "\nPHILO NUMERO : %d\n", philo->name_philo);
	i = 0;
	struct timeval start_think;
	gettimeofday(&start_think, NULL);
	//
	philo->time_think = 100;
	//
	while (i != 1)
	{
		gettimeofday(&philo->ms_think, NULL);
		if (ft_conv_to_ms(philo->ms_think, start_think) >= philo->time_think)
			i = 1;
	}
	dprintf(1, "\nPhilo numero %d a fini de penser\n", philo->name_philo);

	return (0);
}
