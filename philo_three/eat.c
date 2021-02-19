#include "philo_three.h"

void		*philo_eat(t_philo *philo, t_init *init)
{
	int i;
	i = 0;
	display(philo->np, " is eating", philo, init);
	gettimeofday(&philo->ms_died, NULL);
	philo->reload = 1;
	if (philo->nb_eat >= 0 && philo->no_limite == 0)
	{
		struct timeval start_eat;
		gettimeofday(&start_eat, NULL);
		while (i != 1)
		{
			gettimeofday(&philo->ms_eat, NULL);
			if (ft_conv_to_ms(philo->ms_eat, start_eat) >= philo->time_eat || philo->if_die == 1)
				i = 1;
		}
		philo->nb_eat--;
	}
	else
	{
		struct timeval start_eat;
		gettimeofday(&start_eat, NULL);
		while (i != 1)
		{
			gettimeofday(&philo->ms_eat, NULL);
			if (ft_conv_to_ms(philo->ms_eat, start_eat) >= philo->time_eat || philo->if_die == 1)
				i = 1;
		}
	}
	if (philo->nb_eat == 0 && philo->no_limite == 0)
		philo->end_eat = 1;
	return (0);
}
