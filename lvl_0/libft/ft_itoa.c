/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:59:55 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/07 18:59:55 by jibanez-         ###   ########.fr       */
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
	int		a;
	int		i;

	a = n;
	i = 0;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		a;
	int		i;

	i = n;
	a = ft_digitcount(n) + 1;
	if (n < 0)
	{
		str = malloc(a + 2);
		str[0] = '-';
	}
	else
	{
		str = malloc(a + 1);
		a -= 1;
	}
	while (n != 0)
	{
		a--;
		str[a] = ft_absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
