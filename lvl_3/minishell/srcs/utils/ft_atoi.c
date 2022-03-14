/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:26:59 by dareias-          #+#    #+#             */
/*   Updated: 2021/12/22 19:44:24 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_atoi(const char *str)
{
	int					negative;
	unsigned long int	atoix;

	negative = 1;
	atoix = 0;
	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9' && *str)
	{
		atoix = atoix * 10 + ((int)*str - 48);
		str++;
	}
	if (atoix > 9223372036854775807 && negative == 1)
		return (-1);
	else if (atoix > 9223372036854775808U && negative == -1)
		return (0);
	else
		return (atoix * negative);
}
