/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:53:01 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/06 18:53:01 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char const *src, int start, int last)
{
	int i;

	i = 0;
	while (start < last)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = 0;

	return (dest);
}
