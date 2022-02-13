/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:37:45 by jibanez-          #+#    #+#             */
/*   Updated: 2022/02/13 00:29:00 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_eat_timeout(t_philo *philo)
{
	uint64_t	now;

	philo->start_eating = ft_time();
	now = ft_time();
	while (now - philo->start_eating < philo->t_eat)
	{
		usleep(10);
		if ((now - philo->start_eating > philo->t_die))
		{
			death_check(philo, TRUE);
			return (0);
		}
		now = ft_time();
	}
	return (1);
}

int	ft_sleep_timeout(t_philo *philo)
{
	uint64_t	now;
	uint64_t	t_start_sleep;

	t_start_sleep = ft_time();
	now = ft_time();
	while (now - t_start_sleep < philo->t_sleep)
	{
		usleep(10);
		if ((now - philo->start_eating > philo->t_die))
		{
			death_check(philo, TRUE);
			return (0);
		}
		now = ft_time();
	}
	return (1);
}

void	ft_print(t_philo *philo)
{
	uint64_t	delta_t;
	uint64_t	now;

	now = ft_time();
	pthread_mutex_lock(philo->mutex_printer);
	delta_t = now - philo->start_time;
	if (philo->state == DEAD)
		printf("%lu %d died\n", delta_t, philo->id);
	else if (philo->state == EAT)
	{
		printf("%lu %d has taken a fork\n", delta_t, philo->id);
		printf("%lu %d has taken a fork\n", delta_t, philo->id);
		printf("%lu %d is eating\n", delta_t, philo->id);
	}
	else if (philo->state == SLEEP)
		printf("%lu %d is sleeping\n", delta_t, philo->id);
	else if (philo->state == THINK)
		printf("%lu %d is thinking\n", delta_t, philo->id);
	pthread_mutex_unlock(philo->mutex_printer);
}

int	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_left);
	pthread_mutex_lock(philo->mutex_right);
	if ((*philo->fork_left) && (*philo->fork_right))
	{
		(*philo->fork_left) = FALSE;
		(*philo->fork_right) = FALSE;
		pthread_mutex_unlock(philo->mutex_left);
		pthread_mutex_unlock(philo->mutex_right);
	}
	else
	{
		pthread_mutex_unlock(philo->mutex_left);
		pthread_mutex_unlock(philo->mutex_right);
		return (0);
	}
	return (1);
}

void	ft_free_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_left);
	pthread_mutex_lock(philo->mutex_right);
	*philo->fork_left = TRUE;
	*philo->fork_right = TRUE;
	pthread_mutex_unlock(philo->mutex_left);
	pthread_mutex_unlock(philo->mutex_right);
}
