/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:59:55 by jibanez-          #+#    #+#             */
/*   Updated: 2021/05/03 15:24:20 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strreve(char *s)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(s);
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
	return (s);
}

char	*ft_mod_itoa(int n)
{
	char	arr[12];
	int		i;

	ft_memset(arr, 0, 12);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		arr[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	ft_strreve(arr);
	return (ft_strdup(arr));
}
