#include "philo_two.h"

void		*philo_sleep(t_philo *philo)
{
	int i;
	// dprintf(1, "\nPHILO NUMERO : %d\n", philo->name_philo);
	i = 0;
	struct timeval start_sleep;
	gettimeofday(&start_sleep, NULL);
	display(philo->name_philo, " is sleeping", philo);
	while (i != 1)
	{
		gettimeofday(&philo->ms_sleep, NULL);
		if (ft_check_die(philo) == 1)
		{
			sem_wait(philo->perso->s_die);
			philo->philo_die = 1;
			if (philo->perso->if_die == 0)
			{
				philo->perso->if_die = 1;
				display(philo->name_philo, " died", philo);
			}
			sem_post(philo->perso->s_die);
			return (0);
		}
		if (ft_conv_to_ms(philo->ms_sleep, start_sleep) >= philo->time_sleep || philo->perso->if_die == 1)
			i = 1;
	}
	return (0);
}
