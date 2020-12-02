/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:14:30 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/02 17:14:30 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (malloc(ft_strlen(src) * sizeof(*dest + 1)));
	if (dest == '\0')
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
