/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_emul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:41:14 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/09 15:03:15 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	got_eat_time(t_tread *philos)
{
	pthread_mutex_lock(&philos->last_eat_time_mutex);
	philos->last_eat_time = get_time();
	pthread_mutex_unlock(&philos->last_eat_time_mutex);
}

int	ft_fork_take(t_tread *philos, pthread_mutex_t *l_fork,
	pthread_mutex_t *r_fork)
{
	pthread_mutex_lock(l_fork);
	mutex_print(philos, "has taken a fork\n");
	if (philos->philo->num_of_philo == 1)
	{
		pthread_mutex_unlock(l_fork);
		return (1);
	}
	pthread_mutex_lock(r_fork);
	mutex_print(philos, "has taken a fork\n");
	mutex_print(philos, "is eating\n");
	m_sleep(philos->philo->eat_time);
	pthread_mutex_unlock(l_fork);
	pthread_mutex_unlock(r_fork);
	pthread_mutex_lock(&philos->each_eat_mutex);
	philos->each_eat++;
	pthread_mutex_unlock(&philos->each_eat_mutex);
	mutex_print(philos, "is sleeping\n");
	got_eat_time(philos);
	m_sleep(philos->philo->sleep_time);
	mutex_print(philos, "is thinking\n");
	return (0);
}

void	*ft_simulation(t_tread *phil)
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	l_fork = &phil->philo->forks[phil->id];
	r_fork = &phil->philo->forks[(phil->id + 1) % phil->philo->num_of_philo];
	got_eat_time(phil);
	if ((phil->id + 1) % 2 == 0)
		usleep(500);
	while ((!is_dead(phil)) == 1)
	{
		if (ft_fork_take(phil, l_fork, r_fork) == 1)
		{
			got_eat_time(phil);
			return (NULL);
		}
	}
	return (NULL);
}
