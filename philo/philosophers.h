/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:07:04 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/05 16:00:17 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct timeval	t_timeval;
struct					s_philo;

typedef struct s_tread
{
	int				id;
	int				*die;
	int				each_eat;
	long long		last_eat_time;
	struct s_philo	*philo;
	pthread_t		tid;
	pthread_mutex_t	each_eat_mutex;
	pthread_mutex_t	last_eat_time_mutex;
}	t_tread;

typedef struct s_philo
{
	int				num_of_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_number;
	int				die;
	t_tread			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	print_mutex;
}	t_philo;

//philo.c
void			start_emulation(t_philo *philo);

//ft_init.c
void			arg_init(int argc, char **argv, t_philo *philo);
int				check_inputs(int argc, char **argv, t_philo *philo);
int				philo_init(int argc, char **argv, t_philo *philo);

//ft_start_emul.c
int				ft_fork_take(t_tread *philos, pthread_mutex_t *l_fork,
					pthread_mutex_t *r_fork);
void			got_eat_time(t_tread *philos);
void			*ft_simulation(t_tread *phil);

//ft_check_functions.c
void			mutex_print(t_tread *philos, char *str);
int				is_dead(t_tread *philos);
int				check_die(t_philo *philo);
int				check_eat(t_philo *philo);

//ft_time.c
long long		get_time(void);
void			m_sleep(long long time);

//ft_atoi.c
int				ft_atoi(const char *str);

#endif