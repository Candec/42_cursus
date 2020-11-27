/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:44:28 by jibanez-          #+#    #+#             */
/*   Updated: 2020/11/26 16:44:28 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == 0 && src == 0)
		return (0);
	if (dest == src)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}
