#include "philo_one.h"

void        *routine(void *p_data)
{
    t_philo *philo = p_data;
    pthread_mutex_lock(&philo->mt_eat);
    while (philo->end_eat == 0 && philo->no_limite == 0)
    {
        printf("{%d}\n", ft_check_die(philo));
        philo_eat(philo);
        philo_sleep(philo);
        //philo_think(philo);
    }
    while (philo->no_limite == 1 && philo->dead == 0)
    {
        philo_eat(philo);
        philo_sleep(philo);
    }

	pthread_mutex_unlock(&philo->mt_eat);
    return (0);
}
