/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:17:51 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/23 19:17:51 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdint.h>

# define ERROR -1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1

enum
{
	DEAD,
	EAT,
	SLEEP,
	THINK
};

typedef struct s_philo
{
	int				id;
	int				state;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	bool			is_eating;
	bool			is_reasting;
	bool			is_thinking;
	bool			is_dead;
	bool			fork_right;
	bool			fork_left;
	uint64_t		start_time;
	uint64_t		start_eating;
	pthread_mutex_t	*mutex_printer;
	pthread_mutex_t	*mutex_dead;
	pthread_mutex_t	*mutex_right;
	pthread_mutex_t	*mutex_left;
}					t_philo;

typedef struct s_table
{
	int				thinkers;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_think;
	int				n_meals;
	bool			is_dead;
	bool			is_eating;
	int				*fork;
	uint64_t		start_time;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*philo_mutex;
	pthread_mutex_t	mutex_printer;
	pthread_mutex_t	mutex_dead;
}					t_table;

/*
** philo.c
*/
int			ft_check(t_table *table, int argc, char **argv);


/*
** check.c
*/
void		ft_init_forks(t_table *table);
void		ft_init_mutex(t_table *table);
void		ft_init_thinkers(t_table *table);
void		ft_init_thread(t_table *table);
int			ft_init(t_table *table, int argc, char **argv);

/*
** ft_atoi.c
*/
int			ft_atoi(const char *str);

/*
**	utils.c
*/
uint64_t	ft_time(void);
int			ft_eat_timeout(t_philo *philo);
int			ft_sleep_timeout(t_philo *philo);
void		ft_print(t_philo *philo);
int			ft_take_forks(t_philo *philo);
void		ft_free_forks(t_philo *philo);


/*
**	life.c
*/
int			death_check(t_philo *philo, bool is_dead);
void		*life_cycle(void *philo);

#endif