/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:59:55 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/11 15:25:25 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
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

char		*ft_itoa(int n)
{
	char	*str;
	size_t	size_nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size_nbr = ft_digitcount(n);
	if (!(str = malloc((size_nbr + 1) * sizeof(char))))
		return (0);
	str += size_nbr;
	*str-- = '\0';
	while (size_nbr--)
	{
		*str-- = ft_abs(n) % 10 + '0';
		if (-10 < n && n < 0)
		{
			*str-- = '-';
			break ;
		}
		n /= 10;
	}
	return (++str);
}
