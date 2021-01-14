/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:57:08 by jibanez-          #+#    #+#             */
/*   Updated: 2021/01/13 10:56:12 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*a;
	char	*b;

	size = ft_strlen(s1) + ft_strlen(s2) - 1;
	a = malloc(size);
	b = a;
	while (*(s1) != '\0')
	{
		*a = *s1;
		a++;
		s1++;
	}
	while (*(s2) != '\0')
	{
		*a = *s2;
		a++;
		s2++;
	}
	a = '\0';
	return (b);
}
