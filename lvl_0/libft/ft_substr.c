/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:32:01 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/02 17:32:01 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = len - start;
	str = malloc(size);
	if (str == 0 || s == 0)
		return (0);
	while (s[start] && start > len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
