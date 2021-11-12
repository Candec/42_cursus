/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:14:34 by jibanez-          #+#    #+#             */
/*   Updated: 2021/11/12 17:18:56 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_eat(t_philo *philo)
{
	if (!ft_take_forks(philo))
		return ;
	else
	{
		ft_print(philo);
		if (ft_eat_timeout(philo))
			return ;
		philo->n_meals--;
		philo->state = SLEEP;
		ft_free_forks(philo);
	}
}

static void	ft_sleep(t_philo *philo)
{
	ft_print(philo);
	if (ft_sleep_timeout(philo))
		return ;
	philo->state = THINK;
}

static void	ft_think(t_philo *philo)
{
	if (philo->start_eating > 0)
		ft_print(philo);
	philo->state = EAT;
}

int	death_check(t_philo *philo, bool is_dead)
{
	uint64_t	now;

	pthread_mutex_lock(philo->mutex_dead);
	if (philo->is_dead)
	{
		pthread_mutex_unlock(philo->mutex_dead);
		return (0);
	}
	now = ft_time();
	if (is_dead == TRUE
		|| (philo->t_eat > 0 && philo->t_die > (now - philo->start_time)))
	{
		philo->state = DEAD;
		philo->is_dead = 0;
		pthread_mutex_unlock(philo->mutex_dead);
		ft_print(philo);
	}
	else
		pthread_mutex_unlock(philo->mutex_dead);
	return (1);
}

void	*life_cycle(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	while (death_check(philo, FALSE) && philo->n_meals > 0)
	{
		if (philo->state == EAT)
			ft_eat(philo);
		else if (philo->state == SLEEP)
			ft_sleep(philo);
		else if (philo->state == THINK)
			ft_think(philo);
	}
	return (NULL);
}
