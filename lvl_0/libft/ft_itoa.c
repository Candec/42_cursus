/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:59:55 by jibanez-          #+#    #+#             */
/*   Updated: 2021/02/24 16:50:31 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	ft_digitcount(int n)
{
	int	a;
	int	i;

	a = n;
	i = 0;
	if (a == 0)
		i++;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		a;

	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		str = malloc(ft_digitcount(n) + 2);
		str[0] = '-';
	}
	else if (n == 0)
	{
		str = calloc(1, ft_digitcount(n) + 1);
		str[0] = '0';
	}
	else
		str = malloc(ft_digitcount(n) + 2);
	while (n != 0)
	{
		a = ft_digitcount(n);
		str[--a] = ft_absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
