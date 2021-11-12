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

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (!ft_check(table, argc, argv))
	{
		return (0);
	}
	// ft_think(table);
}
