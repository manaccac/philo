#include "philo_three.h"

void		*routine(t_philo *philo)
{
	// t_philo *philo = p_data;
	while (philo->no_limite == 0 && philo->nb_eat > 0 && philo->p->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
		{
			sem_wait(philo->p->s_die);
			philo->philo_die = 1;
			if (philo->p->if_die == 0)
			{
				philo->p->if_die = 1;
				display(philo->np, " died", philo);
			}
			sem_post(philo->p->s_die);
			return (0);
		}
		if (philo->p->fork / 2 >= 1)
		{
			if (philo->p->if_die == 1)
				return (0);
			philo->p->fork -= 2;
			sem_wait(philo->p->s_fork);
			display(philo->np, " has taken a fork", philo);
			display(philo->np, " has taken a fork", philo);
			if (philo->p->if_die == 1)
			{
				sem_post(philo->p->s_fork);
				return (0);
			}
			philo_eat(philo);
			philo->p->fork += 2;
			sem_post(philo->p->s_fork);
			if (philo->nb_eat > 0)
			{
				if (philo->p->if_die == 1)
					return (0);
				philo_sleep(philo);
				if (philo->p->if_die == 1)
					return (0);
				display(philo->np, " is thinking", philo);
			}
		}
	}
	//
	while (philo->no_limite == 1 && philo->p->if_die == 0)
	{
		usleep(10);
		if (ft_check_die(philo) == 1)
		{
			sem_wait(philo->p->s_die);
			philo->philo_die = 1;
			if (philo->p->if_die == 0)
			{
				philo->p->if_die = 1;
				display(philo->np, " died", philo);
			}
			sem_post(philo->p->s_die);
			return (0);
		}
		if (philo->p->fork / 2 >= 1)
		{
			if (philo->p->if_die == 1)
				return (0);
			philo->p->fork -= 2;
			sem_wait(philo->p->s_fork);
			display(philo->np, " has taken a fork", philo);
			display(philo->np, " has taken a fork", philo);
			if (philo->p->if_die == 1)
			{
				sem_post(philo->p->s_fork);
				return (0);
			}
			philo_eat(philo);
			philo->p->fork += 2;
			sem_post(philo->p->s_fork);
			if (philo->p->if_die == 1)
				return (0);
			philo_sleep(philo);
			if (philo->p->if_die == 1)
				return (0);
			display(philo->np, " is thinking", philo);
		}
	}
	return (0);
}
