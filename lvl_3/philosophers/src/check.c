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

uint64_t	ft_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

int ft_init(t_table *table, int argc, char **argv)
{
    table->thinkers = ft_atoi(argv[1]);
    table->t_eat = ft_atoi(argv[2]);
    table->t_sleep = ft_atoi(argv[3]);
    table->is_dead = FALSE;
    table->is_eating = FALSE;
    table->start_time = ft_time();
    ft_init_thinkers(table);
}

int ft_check(t_table *table, int argc, char **argv)
{
    if (argc == 5)
    {
        table->n_meals = -1;
        ft_init(table, argc, argv);
    }
    else if (argc == 6)
    {
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