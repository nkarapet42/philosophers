/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:44:37 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/09 14:35:48 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>
# include <limits.h>

# define EAT_SEM "/eat"
# define LAST_EAT_SEM "/last_eat"
# define FORKS_SEM "/forks"
# define PRINT_SEM "/print"
# define DIE_SEM "/die"

typedef struct s_tread
{
	int				id;
	int				*die;
	int				each_eat;
	long long		last_eat_time;
	pid_t			pid;
	pthread_t		tid;
	struct s_philo	*philo;
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
	sem_t			*each_eat_sem;
	sem_t			*last_eat_time_sem;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*die_sem;
}	t_philo;

//ft_bonus_init.c
int			open_sem(t_philo *philo);
void		arg_init(int argc, char **argv, t_philo *philo);
int			check_inputs(int argc, char **argv, t_philo *philo);
int			philo_init(int argc, char **argv, t_philo *philo);

//ft_bonus_atoi.c
int			ft_atoi(const char *str);

//ft_start_emul_bonus.c
void		close_and_unlink(t_philo *philo);
void		got_eat_time(t_tread *philos);
void		*check_function(t_tread *philos);
void		ft_simulation(t_tread *philos);
int			start_simulation(t_philo *philo);

//ft_check_functions_bonus.c
void		sem_print(t_tread *philos, char *str);
int			is_dead(t_tread *philos);
int			check_die(t_tread *philos);
int			check_eat(t_tread *philos);

//ft_time_bonus.cs
long long	get_time(void);
void		m_sleep(long long time);

#endif