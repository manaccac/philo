#include "philo_one.h"

void		*philo_sleep(t_philo *philo)
{
	int i;
	// dprintf(1, "\nPHILO NUMERO : %d\n", philo->name_philo);
	i = 0;
	struct timeval start_sleep;
	gettimeofday(&start_sleep, NULL);
	while (i != 1)
	{
		gettimeofday(&philo->ms_sleep, NULL);
		if (ft_conv_to_ms(philo->ms_sleep, start_sleep) >= philo->time_sleep)
			i = 1;
	}
	display(philo->name_philo, " is sleeping", philo);
	return (0);
}
