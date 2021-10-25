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

enum
{
    FALSE,
    TRUE
};

typedef struct  s_philo
{
    int             id;
    bool            is_eating;
    bool            is_reasting;
    bool            is_thinking;
    bool            is_dead;
    bool            fork_right;
    bool            fork_left;
    int             n_meals;
    uint64_t        start_time;
    uint64_t        start_eating;
    pthread_mutex_t	*mutex_printer;
	pthread_mutex_t	*mutex_dead;
	pthread_mutex_t	*mutex_right;
	pthread_mutex_t	*mutex_left;
}               t_philo;

typedef struct  s_table
{
    int             thinkers;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             t_think;
    int             n_meals;
    bool            is_dead;
    bool            is_eating;
    int             *fork;
    uint64_t        start_time;
    t_philo         *philo;
    pthread_t       *thread;
    pthread_mutex_t	*philo_mutex;
	pthread_mutex_t	mutex_printer;
	pthread_mutex_t	mutex_dead;
}               t_table;

/*
** check.c
*/

int ft_check(t_table *table, int argc, char **argv);

/*
** ft_atoi.c
*/
int	ft_atoi(const char *str);


#endif