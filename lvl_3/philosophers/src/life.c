/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:14:34 by jibanez-          #+#    #+#             */
/*   Updated: 2022/02/12 19:09:33 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_eat(t_philo *philo)
{
	if (!ft_take_forks(philo))
		return (0);
	else
	{
		ft_print(philo);
		if (!ft_eat_timeout(philo))
			return (0);
		philo->n_meals--;
		philo->state = SLEEP;
		ft_free_forks(philo);
	}
	return (1);
}

static int	ft_sleep(t_philo *philo)
{
	ft_print(philo);
	if (!ft_sleep_timeout(philo))
		return (1);
	philo->state = THINK;
	return (0);
}

static void	ft_think(t_philo *philo)
{
	if (philo->start_eating != 0)
		ft_print(philo);
	philo->state = EAT;
}

int	death_check(t_philo *philo, int is_dead)
{
	uint64_t	now;

	pthread_mutex_lock(philo->mutex_dead);
	if (*philo->is_alive == FALSE)
	{
		pthread_mutex_unlock(philo->mutex_dead);
		return (0);
	}
	now = ft_time();
	if (is_dead == TRUE
		|| (philo->start_eating != 0
			&& philo->t_die < (now - philo->start_eating)))
	{
		philo->state = DEAD;
		*philo->is_alive = 0;
		pthread_mutex_unlock(philo->mutex_dead);
		ft_print(philo);
		return (0);
	}
	else
		pthread_mutex_unlock(philo->mutex_dead);
	return (1);
}

void	*life_cycle(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (death_check(philo, FALSE) && philo->n_meals != 0)
	{
		if (philo->state == EAT)
		{
			if (ft_eat(philo))
				continue ;
		}
		else if (philo->state == SLEEP)
		{
			if (ft_sleep(philo))
				return (NULL);
		}
		else if (philo->state == THINK)
		{
			ft_think(philo);
		}
	}
	return (NULL);
}
