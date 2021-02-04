#include "philo_one.h"

void		*philo_eat(t_philo *philo)
{
	int i;
	i = 0;
	gettimeofday(&philo->ms_died, NULL);
	if (philo->nb_eat >= 0 && philo->no_limite == 0)
	{
		struct timeval start_eat;
		gettimeofday(&start_eat, NULL);
		while (i != 1)
		{
			gettimeofday(&philo->ms_eat, NULL);
			if (ft_conv_to_ms(philo->ms_eat, start_eat) >= philo->time_eat)
				i = 1;
		}
		philo->nb_eat--;
		display(philo->name_philo, " is eating", philo);
		// if (philo->nb_eat == 0)
			// dprintf(1, "%d a fini de manger\n", philo->name_philo);
	}
	else
	{
		struct timeval start_eat;
		gettimeofday(&start_eat, NULL);
		while (i != 1)
		{
			gettimeofday(&philo->ms_eat, NULL);
			if (ft_conv_to_ms(philo->ms_eat, start_eat) >= philo->time_eat)
				i = 1;
		}
		// dprintf(1, "\n%d a fini de manger\n", philo->name_philo);
	}
	if (philo->nb_eat == 0)
		philo->end_eat = 1;
	return (0);
}
