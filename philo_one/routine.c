#include "philo_one.h"

void		*routine(void *p_data)
{
	t_philo *philo = p_data;
	while (philo->no_limite == 0 && philo->end_eat == 0)
	{
		if (ft_check_die(philo) == 1)
		{
			ft_putstr("A philosopher died :'(\n");
			philo->philo_die = 1;
			return (0);
		}
		if ((philo->perso->fork_perso[philo->name_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1) ||
			(philo->name_philo == 0 && (philo->perso->fork_perso[philo->nb_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1)))
		{
			philo->perso->fork_perso[philo->name_philo - 1] = 0;
			philo->perso->fork_perso[philo->name_philo] = 0;
			if (philo->perso->fork == 0)
				pthread_mutex_lock(philo->perso->l_fork);
			display(philo->name_philo, " has taken a fork", philo);
			philo->perso->fork -= 1;
			if (philo->perso->fork == 0)
				pthread_mutex_lock(philo->perso->r_fork);
			display(philo->name_philo, " has taken a fork", philo);
			philo->perso->fork -= 1;
			philo->perso->eating[philo->name_philo] = 1;
			philo_eat(philo);
		}
		if (philo->perso->eating[philo->name_philo] == 1)
		{
			if (philo->first_eat == 0)
				philo->first_eat = 1;
			pthread_mutex_unlock(philo->perso->l_fork);
			philo->perso->fork += 1;
			pthread_mutex_unlock(philo->perso->r_fork);
			philo->perso->fork += 1;
			philo->perso->eating[philo->name_philo] = 0;
			philo->perso->fork_perso[philo->name_philo - 1] = 1;
			philo->perso->fork_perso[philo->name_philo] = 1;
		}
		if (philo->first_eat == 1)
		{
			philo_sleep(philo);
			philo_think(philo);
		}
	}
	while (philo->no_limite == 1 && philo->dead == 0)
	{
		printf("{%d}\n", ft_check_die(philo));
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (0);
}
