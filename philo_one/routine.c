#include "philo_one.h"

void        *routine(void *p_data)
{
    t_philo *philo = p_data;
    while (philo->end_eat == 0 && philo->no_limite == 0)
    {
		printf("{%d}\n", ft_check_die(philo));
		if (philo->name_philo == 0)
		{
			if (philo->perso->eating[philo->name_philo + 1] == 0 && philo->perso->eating[philo->nb_philo] == 0)
			{
				pthread_mutex_lock(philo->perso->l_fork);
				dprintf(1, "philo number %d has taken a fork\n", philo->name_philo);
				philo->perso->fork -= 1;
				pthread_mutex_lock(philo->perso->r_fork);
				dprintf(1, "philo number %d has taken a fork\n", philo->name_philo);
				philo->perso->fork -= 1;
				philo->perso->eating[philo->name_philo] = 1;
				dprintf(1, "FORK = %d\n", philo->perso->fork);
				philo_eat(philo);
			}
		}
		else if (philo->name_philo == philo->nb_philo)
		{
			if (philo->perso->eating[0] == 0 && philo->perso->eating[philo->name_philo - 1] == 0)
			{
				pthread_mutex_lock(philo->perso->l_fork);
				dprintf(1, "philo number %d has taken a fork\n", philo->name_philo);
				philo->perso->fork -= 1;
				pthread_mutex_lock(philo->perso->r_fork);
				dprintf(1, "philo number %d has taken a fork\n", philo->name_philo);
				philo->perso->fork -= 1;
				philo->perso->eating[philo->name_philo] = 1;
				dprintf(1, "FORK = %d\n", philo->perso->fork);
				philo_eat(philo);
			}
		}
		else
		{
			if (philo->perso->eating[philo->name_philo + 1] == 0 && philo->perso->eating[philo->name_philo - 1] == 0)
			{
				pthread_mutex_lock(philo->perso->l_fork);
				dprintf(1, "philo number %d has taken a fork\n", philo->name_philo);
				philo->perso->fork -= 1;
				pthread_mutex_lock(philo->perso->r_fork);
				dprintf(1, "philo number %d has taken a fork\n", philo->name_philo);
				philo->perso->fork -= 1;
				philo->perso->eating[philo->name_philo] = 1;
				dprintf(1, "FORK = %d\n", philo->perso->fork);
				philo_eat(philo);
			}
		}
		pthread_mutex_unlock(philo->perso->l_fork);
		dprintf(1, "philo number %d has rendering a fork\n", philo->name_philo);
		philo->perso->fork += 1;
		pthread_mutex_unlock(philo->perso->r_fork);
		dprintf(1, "philo number %d has rendering a fork\n", philo->name_philo);
		philo->perso->fork += 1;
		dprintf(1, "FORK = %d\n", philo->perso->fork);
		philo->perso->eating[philo->name_philo] = 0;
        philo_sleep(philo);
        philo_think(philo);
    }
    while (philo->no_limite == 1 && philo->dead == 0)
    {
        printf("{%d}\n", ft_check_die(philo));
        philo_eat(philo);
        philo_sleep(philo);
    }
    return (0);
}
