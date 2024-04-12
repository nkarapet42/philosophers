/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:53:42 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/05 16:55:14 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_print(t_tread *philos, char *str)
{
	pthread_mutex_lock(&philos->philo->print_mutex);
	if ((!is_dead(philos)) == 1)
		printf("%lld %d %s", get_time(), philos->id + 1, str);
	pthread_mutex_unlock(&philos->philo->print_mutex);
}

int	is_dead(t_tread *philos)
{
	int	philos_die;

	pthread_mutex_lock(&philos->philo->die_mutex);
	philos_die = *philos->die;
	pthread_mutex_unlock(&philos->philo->die_mutex);
	return (philos_die);
}

int	check_die(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num_of_philo)
	{
		pthread_mutex_lock(&philo->philos[i].last_eat_time_mutex);
		if (get_time() - philo->philos[i].last_eat_time >= philo->die_time)
		{
			pthread_mutex_lock(&philo->die_mutex);
			philo->die = 1;
			pthread_mutex_unlock(&philo->die_mutex);
			pthread_mutex_lock(&philo->print_mutex);
			printf("%lld %d %s", get_time(), philo->philos[i].id + 1, "died\n");
			pthread_mutex_unlock(&philo->print_mutex);
			pthread_mutex_unlock(&philo->philos[i].last_eat_time_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->philos[i].last_eat_time_mutex);
	}
	return (0);
}

int	check_eat(t_philo *philo)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (philo->eat_number < 0)
		return (0);
	while (++i < philo->num_of_philo)
	{
		pthread_mutex_lock(&philo->philos[i].each_eat_mutex);
		if (philo->philos[i].each_eat >= philo->eat_number)
			count++;
		pthread_mutex_unlock(&philo->philos[i].each_eat_mutex);
	}
	if (count == philo->num_of_philo)
	{
		pthread_mutex_lock(&philo->die_mutex);
		philo->die = 1;
		pthread_mutex_unlock(&philo->die_mutex);
		return (1);
	}
	return (0);
}
