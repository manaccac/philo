#include "philo_one.h"

void        *routine(void *p_data)
{
    t_philo *philo = p_data;
    if (philo->nb_eat != 0)
    {
        // pthread_mutex_lock(&philo->mt_eat);
        philo_eat(philo);
    }
    return (0);
}
