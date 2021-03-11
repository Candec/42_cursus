/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:14:30 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/11 15:38:12 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	char	*dest;

	size = ft_strlen(src);
	dest = malloc(size * sizeof(char) + 1);
	if (dest == '\0')
		return (0);
	ft_strlcpy(dest, src, size + 1);
	return (dest);
}
