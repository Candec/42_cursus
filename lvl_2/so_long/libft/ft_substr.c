/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:32:01 by jibanez-          #+#    #+#             */
/*   Updated: 2021/02/10 20:14:24 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		size = ft_strlen(s) + 1;
	else
		size = len + 1;
	sub = (char *)ft_calloc(size, sizeof(char));
	if (!(sub))
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (sub);
	i = 0;
	while (*(s + start) && i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
