/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:59:21 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/12 16:59:40 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_counter(int n);
static char	*ft_itoa_neg(char *res, int n, int counter);

char	*ft_itoa(int n)
{
	int		counter;
	char	*res;

	counter = ft_counter(n);
	res = malloc(counter + 1);
	if (!res)
		return (NULL);
	res[counter--] = '\0';
	if (n < 0)
	{
		res = ft_itoa_neg(res, n, counter);
		return (res);
	}
	while (counter >= 0)
	{
		res[counter--] = (n % 10) + 48;
		n = n / 10;
	}
	return (res);
}

static char	*ft_itoa_neg(char *res, int n, int counter)
{
	if (n == -2147483648)
	{
		res[counter--] = 8 + 48;
		n = n / 10;
	}
	res[0] = '-';
	n = -n;
	while (counter >= 1)
	{
		res[counter--] = (n % 10) + 48;
		n = n / 10;
	}
	return (res);
}

static int	ft_counter(int n)
{
	int	counter;

	counter = 1;
	if (n == -2147483648)
		n = -2147483647;
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n > 9)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}
