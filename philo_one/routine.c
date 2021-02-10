#include "philo_one.h"

void		*routine(void *p_data)
{
	t_philo *philo = p_data;
	while (philo->no_limite == 0 && philo->nb_eat > 0 && philo->perso->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
		{
			pthread_mutex_lock(philo->perso->die);
			philo->philo_die = 1;
			if (philo->perso->if_die == 0)
			{
				philo->perso->if_die = 1;
				display(philo->name_philo, " died", philo);
			}
			pthread_mutex_unlock(philo->perso->die);
			return (0);
		}
		if (philo->perso->fork / 2 >= 1)
		{
			if ((philo->perso->fork_perso[philo->name_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1) ||
				(philo->name_philo == 0 && (philo->perso->fork_perso[philo->nb_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1)))
			{
				if (philo->perso->fork / 2 >= 1)
				{
					philo->perso->fork_perso[philo->name_philo] = 0;
					if (philo->name_philo != 0)
						philo->perso->fork_perso[philo->name_philo - 1] = 0;
					else
						philo->perso->fork_perso[philo->nb_philo - 1] = 0;
					if (philo->perso->if_die == 1)
						return (0);
					pthread_mutex_lock(&philo->perso->l_fork[philo->name_philo]);
					display(philo->name_philo, " has taken a fork", philo);
					philo->perso->fork -= 1;
					pthread_mutex_lock(&philo->perso->r_fork[philo->name_philo]);
					display(philo->name_philo, " has taken a fork", philo);
					philo->perso->fork -= 1;
					if (philo->perso->if_die == 1)
					{
						pthread_mutex_unlock(&philo->perso->l_fork[philo->name_philo]);
						pthread_mutex_unlock(&philo->perso->r_fork[philo->name_philo]);
						return (0);
					}
					philo_eat(philo);
					pthread_mutex_unlock(&philo->perso->l_fork[philo->name_philo]);
					pthread_mutex_unlock(&philo->perso->r_fork[philo->name_philo]);
					philo->perso->fork += 2;
					philo->perso->fork_perso[philo->name_philo] = 1;
					if (philo->name_philo != 0)
						philo->perso->fork_perso[philo->name_philo - 1] = 1;
					else
						philo->perso->fork_perso[philo->nb_philo - 1] = 1;
					if (philo->perso->if_die == 1)
						return (0);
					if (philo->nb_eat > 0)
					{
						philo_sleep(philo);
						if (philo->perso->if_die == 1)
							return (0);
						display(philo->name_philo, " is thinking", philo);
					}
				}
			}
		}
	}
	//
	//
	//
	//
	while (philo->no_limite == 1 && philo->perso->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
		{
			pthread_mutex_lock(philo->perso->die);
			philo->philo_die = 1;
			if (philo->perso->if_die == 0)
			{
				philo->perso->if_die = 1;
				display(philo->name_philo, " died", philo);
			}
			pthread_mutex_unlock(philo->perso->die);
			return (0);
		}
		if (philo->perso->fork / 2 >= 1)
		{
			if ((philo->perso->fork_perso[philo->name_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1) ||
				(philo->name_philo == 0 && (philo->perso->fork_perso[philo->nb_philo - 1] == 1 && philo->perso->fork_perso[philo->name_philo] == 1)))
			{
				if (philo->perso->fork / 2 >= 1)
				{
					philo->perso->fork_perso[philo->name_philo] = 0;
					if (philo->name_philo != 0)
						philo->perso->fork_perso[philo->name_philo - 1] = 0;
					else
						philo->perso->fork_perso[philo->nb_philo - 1] = 0;
					if (philo->perso->if_die == 1)
						return (0);
					pthread_mutex_lock(&philo->perso->l_fork[philo->name_philo]);
					display(philo->name_philo, " has taken a fork", philo);
					philo->perso->fork -= 1;
					pthread_mutex_lock(&philo->perso->r_fork[philo->name_philo]);
					display(philo->name_philo, " has taken a fork", philo);
					philo->perso->fork -= 1;
					if (philo->perso->if_die == 1)
					{
						pthread_mutex_unlock(&philo->perso->l_fork[philo->name_philo]);
						pthread_mutex_unlock(&philo->perso->r_fork[philo->name_philo]);
						return (0);
					}
					philo_eat(philo);
					pthread_mutex_unlock(&philo->perso->l_fork[philo->name_philo]);
					pthread_mutex_unlock(&philo->perso->r_fork[philo->name_philo]);
					philo->perso->fork += 2;
					philo->perso->fork_perso[philo->name_philo] = 1;
					if (philo->name_philo != 0)
						philo->perso->fork_perso[philo->name_philo - 1] = 1;
					else
						philo->perso->fork_perso[philo->nb_philo - 1] = 1;
					if (philo->perso->if_die == 1)
						return (0);
					philo_sleep(philo);
					if (philo->perso->if_die == 1)
						return (0);
					display(philo->name_philo, " is thinking", philo);
				}
			}
		}
	}
	return (0);
}
