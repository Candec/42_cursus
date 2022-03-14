/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_terminated_arrays.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:37:55 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 22:37:57 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nta_size(char **array)
{
	int	size;

	size = 0;
	if (!array)
		return (0);
	while (array[size] != NULL)
		size++;
	return (size);
}

int	nta_on_even_size(char **array)
{
	int	size;

	size = 0;
	if (!array)
		return (0);
	while (array[size] != NULL || size % 2 == 1)
		size++;
	return (size);
}
