#include "philo_one.h"

void		*routine(void *p_data)
{
	t_philo *philo = p_data;
	while (philo->no_limite == 0 && philo->nb_eat > 0)
	{
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
		if (philo->perso->fork / 2 >= 1)
		{
			if (philo->perso->if_die == 1)
				return (0);
			if (philo->perso->fork / 2 >= 1)
			{
				philo->perso->fork -= 2;
				sem_wait(philo->perso->s_fork);
				display(philo->name_philo, " has taken a fork", philo);
				display(philo->name_philo, " has taken a fork", philo);
				if (philo->perso->if_die == 1)
				{
					sem_post(philo->perso->s_fork);
					return (0);
				}
				philo_eat(philo);
				philo->perso->fork += 2;
				sem_post(philo->perso->s_fork);
				if (philo->nb_eat > 0)
				{
					if (philo->perso->if_die == 1)
						return (0);
					display(philo->name_philo, " is sleeping", philo);
					usleep(philo->time_sleep * 1000);
					if (philo->perso->if_die == 1)
						return (0);
					display(philo->name_philo, " is thinking", philo);
				}
			}
		}
	}
	//
	//
	//
	//
	while (philo->no_limite == 1 && (philo->dead == 0 || philo->perso->if_die == 0))
	{
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
		sem_post(philo->perso->s_die);
		if (philo->perso->fork / 2 >= 1)
		{
			if (philo->perso->if_die == 1)
				return (0);
			if (philo->perso->fork / 2 >= 1)
			{
				philo->perso->fork -= 2;
				sem_wait(philo->perso->s_fork);
				display(philo->name_philo, " has taken a fork", philo);
				display(philo->name_philo, " has taken a fork", philo);
				if (philo->perso->if_die == 1)
				{
					sem_post(philo->perso->s_fork);
					return (0);
				}
				philo_eat(philo);
				philo->perso->fork += 2;
				sem_post(philo->perso->s_fork);
				if (philo->perso->if_die == 1)
					return (0);
				display(philo->name_philo, " is sleeping", philo);
				usleep(philo->time_sleep * 1000);
				if (philo->perso->if_die == 1)
					return (0);
				display(philo->name_philo, " is thinking", philo);
			}
		}
	}
	return (0);
}
