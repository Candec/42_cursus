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

void	ft_init_thread(t_table *table)
{
	int			i;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * table->thinkers);
	i = -1;
	while (++i < table->thinkers)
	{
		printf("i: %d < n: %d\n", i, table->thinkers);
		pthread_create(&thread[i], NULL, &life_cycle, &table->philo[i]);
	}
	write(1, "HERE\n", 6);
	i = -1;
	while (++i < table->thinkers)
	{
		pthread_join(thread[i], NULL);

	}
	table->thread = thread;
}

void	ft_init_forks(t_table *table)
{
	int		i;
	int		*forks;

	i = -1;
	forks = malloc(sizeof(int) * table->thinkers);
	if (!forks)
	{
		write(1, "MALLOC ERROR\n", 14);
		return ;
	}
	while (++i < table->thinkers)
		forks[i] = 1;
	table->fork = forks;
}

void	ft_init_mutex(t_table *table)
{
	int	i;
	pthread_mutex_t *mutex;

	mutex = malloc(sizeof(pthread_mutex_t) * table->thinkers);
	if (!mutex)
	{
		write(1, "MALLOC ERROR\n", 14);
		return ;
	}
	while (++i < table->thinkers)
		pthread_mutex_init(&mutex[i], NULL);
	table->philo_mutex = mutex;
}

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
		table->philo[i].is_eating = &table->is_eating;
		table->philo[i].is_dead = &table->is_dead;
		table->philo[i].fork_left = &table->fork[i];
		table->philo[i].fork_right = &table->fork[(i + 1) % table->thinkers];
		table->philo[i].mutex_left = &table->philo_mutex[i];
		table->philo[i].mutex_right = &table->philo_mutex[(i + 1) % table->thinkers];
		table->philo[i].mutex_printer = &table->mutex_printer;
		table->philo[i].mutex_dead = &table->mutex_dead;
		table->philo[i].state = THINK;
		table->philo[i].start_time = table->start_time;
		table->philo[i].start_eating = 0;


		// //printf para ver inicialización
		// printf("id: %d\nt_die: %ld\nt_eat: %ld\nt_sleep: %ld\nn_meals: %d\nis_eating: %d\nis_dead: %d\nfork_left: %ls\nfork_right: %ls\nstate: %d\nstart_time: %ld\nstart_eating: %ld\n\n\n",
		// table->philo[i].id,
		// table->philo[i].t_die, 
		// table->philo[i].t_eat,
		// table->philo[i].t_sleep,
		// table->philo[i].n_meals,
		// table->philo[i].is_eating[0],
		// table->philo[i].is_dead[0],
		// table->philo[i].fork_left,
		// table->philo[i].fork_right,
		// table->philo[i].state,
		// table->philo[i].start_time,
		// table->philo[i].start_eating);
	}
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
	ft_init_forks(table);
	ft_init_mutex(table);
	pthread_mutex_init(&table->mutex_printer, NULL);
	pthread_mutex_init(&table->mutex_dead, NULL);
	ft_init_thinkers(table);
	ft_init_thread(table);
	return (0);
}
