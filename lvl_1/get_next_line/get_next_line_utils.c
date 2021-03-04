/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:08 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/04 20:07:59 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	if (n == 0)
		return (s);
	str = (unsigned char *)s;
	while (n--)
		*str++ = (unsigned char)c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*m;

	m = malloc(size * nmemb);
	if (m == 0)
		return (0);
	ft_memset(m, 0, size * nmemb);
	return (m);
}
