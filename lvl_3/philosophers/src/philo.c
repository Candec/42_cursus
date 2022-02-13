/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:17:58 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/23 19:17:58 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

uint64_t	ft_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	ft_exit(t_table *table)
{
	int	i;

	i = -1;
	free(table->fork);
	free(table->philo);
	free(table->thread);
	while (++i < table->thinkers)
		pthread_mutex_destroy(&table->mutex[i]);
	free(table->mutex);
	free(table);
}

int	ft_check(t_table *table, int argc, char **argv)
{
	if (argc == 5)
	{
		table->n_meals = -1;
		ft_init(table, argv);
	}
	else if (argc == 6)
	{
		table->n_meals = ft_atoi(argv[5]);
		ft_init(table, argv);
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (argc == 5 || argc == 6)
	{
		table = malloc(sizeof(t_table));
		if (!table)
		{
			write(1, "MALLOC PROBLEM\n", 16);
			return (ERROR);
		}
		if (ft_atoi(argv[1]) == 1)
		{
			printf("0 1 has taken a fork\n");
			usleep(ft_atoi(argv[2]));
			printf("%d 1 died\n", ft_atoi(argv[2]));
			return (SUCCESS);
		}
		if (!ft_check(table, argc, argv))
			ft_exit(table);
		return (SUCCESS);
	}
	else
		write(1, "INVALID NUMBER OF ARGUMENTS\n", 29);
	return (ERROR);
}
