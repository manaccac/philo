#include "philo_three.h"

void		*philo_sleep(t_philo *philo, t_init *init)
{
	int i;
	// dprintf(1, "\nPHILO NUMERO : %d\n", philo->np);
	i = 0;
	struct timeval start_sleep;
	gettimeofday(&start_sleep, NULL);
	display(philo->np, " is sleeping", philo, init);
	while (i != 1)
	{
		gettimeofday(&philo->ms_sleep, NULL);
		if (ft_check_die(philo) == 1)
		{
			sem_wait(init->s_die);
			philo->philo_die = 1;
			if (philo->if_die == 0)
			{
				philo->if_die = 1;
				display(philo->np, " died", philo, init);
			}
			sem_post(init->s_die);
			return (0);
		}
		if (ft_conv_to_ms(philo->ms_sleep, start_sleep) >= philo->time_sleep || philo->if_die == 1)
			i = 1;
	}
	return (0);
}