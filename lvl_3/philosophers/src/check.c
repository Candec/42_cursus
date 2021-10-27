/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:43:26 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/25 18:43:26 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_init_thinkers(t_table *table)
{
	int i;

	i = -1;
	table->philo = malloc(sizeof(t_philo) * table->thinkers);
	if (table->philo == NULL)
		return ;
	while (++i < table->thinkers)
	{
		table->philo[i].id = i + 1;
		table->philo[i].t_die = table->t_die;
		table->philo[i].t_eat = table->t_eat;
		table->philo[i].t_sleep = table->t_sleep;
		table->philo[i].n_meals = table->n_meals;
		table->philo[i].is_eating = table->is_eating;
		table->philo[i].is_dead = table->is_dead;
		table->philo[i].mutex_left = table->fork[i];
		table->philo[i].fork_left = table->fork[i];
		table->philo[i].mutex_right = table->fork[(i + 1) % table->thinkers];
		table->philo[i].fork_right = table->fork[(i + 1) % table->thinkers];
		table->philo[i].mutex_printer = table->mutex_printer;
		table->philo[i].mutex_dead = table->mutex_dead;
		

	}
}

uint64_t	ft_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

int	ft_init(t_table *table, int argc, char **argv)
{
	table->thinkers = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->is_dead = FALSE;
	table->is_eating = FALSE;
	table->start_time = ft_time();
	if (table->thinkers == 0 || table->t_die == 0 || table->t_eat == 0
		|| table->t_sleep == 0 || table->n_meals == 0)
	{
		free(table);
		return (ERROR);
	}
	ft_init_thinkers(table);
}

int	ft_check(t_table *table, int argc, char **argv)
{
	if (argc == 5)
	{
		table = malloc(sizeof(t_table));
		if (!table)
			return (ERROR);
		table->n_meals = -1;
		ft_init(table, argc, argv);
	}
	else if (argc == 6)
	{
		table = malloc(sizeof(t_table));
		if (!table)
			return (ERROR);
		table->n_meals = ft_atoi(argv[5]);
		ft_init(table, argc, argv);
	}
	else
	{
		write(1, "INVALID NUMBER OF ARGUMENTS\n", 29);
		return (ERROR);
	}
	return (SUCCESS);
}
