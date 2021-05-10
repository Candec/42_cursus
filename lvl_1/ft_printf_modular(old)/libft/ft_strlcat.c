/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:51:32 by jibanez-          #+#    #+#             */
/*   Updated: 2021/02/24 15:03:52 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		dest_len;

	d = dst;
	s = src;
	i = size;
	while (i-- != 0 && *d != '\0')
		d++;
	dest_len = d - dst;
	i = size - dest_len;
	if (i == 0)
		return (dest_len + ft_strlen(s));
	while (*s)
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (dest_len + (s - src));
}
