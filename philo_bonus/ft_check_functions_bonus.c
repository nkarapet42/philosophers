/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_functions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:53:42 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/06 18:45:32 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	sem_print(t_tread *philos, char *str)
{
	sem_wait(philos->philo->print_sem);
	if ((!is_dead(philos)) == 1)
		printf("%lld %d %s", get_time(), philos->id + 1, str);
	sem_post(philos->philo->print_sem);
}

int	is_dead(t_tread *philos)
{
	int	philos_die;

	sem_wait(philos->philo->die_sem);
	philos_die = *philos->die;
	sem_post(philos->philo->die_sem);
	return (philos_die);
}

int	check_die(t_tread *philos)
{
	sem_wait(philos->philo->last_eat_time_sem);
	if (get_time() - philos->last_eat_time >= philos->philo->die_time)
	{
		sem_wait(philos->philo->die_sem);
		philos->philo->die = 1;
		sem_post(philos->philo->die_sem);
		sem_wait(philos->philo->print_sem);
		printf("%lld %d %s", get_time(), philos->id + 1, "died\n");
		sem_post(philos->philo->last_eat_time_sem);
		exit(1);
	}
	sem_post(philos->philo->last_eat_time_sem);
	return (0);
}

int	check_eat(t_tread *philos)
{
	sem_wait(philos->philo->each_eat_sem);
	if (philos->each_eat == philos->philo->eat_number)
	{
		sem_wait(philos->philo->die_sem);
		philos->philo->die = 1;
		sem_post(philos->philo->die_sem);
		sem_post(philos->philo->each_eat_sem);
		exit (0);
	}
	sem_post(philos->philo->each_eat_sem);
	return (0);
}
