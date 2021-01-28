/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:08 by jibanez-          #+#    #+#             */
/*   Updated: 2021/01/28 20:56:38 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	return (ft_memalloc((size + 1) * sizeof(char)));
}

void	*ft_memalloc(size_t size)
{
	void	*m;

	m = malloc(size);
	if (m == NULL)
		return (NULL);
	ft_memset(m, 0, size);
	return (m);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;

	if (n == 0)
		return (s);
	str = (unsigned char *)s;
	while (n--)
		*str++ = (unsigned char)c;
	return (s);
}

int		ft_memdel(void **m)
{
	if (*m)
	{
		ft_memset(*m, 0, ft_strlen(*m));
		free(*m);
		*m = NULL;
		return (1);
	}
	return (0);
}
