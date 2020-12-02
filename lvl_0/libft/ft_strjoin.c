/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:57:08 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/02 17:57:08 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*a;

	size = ft_strlen(s1) + ft_strlen(s2) - 1;
	a = malloc(size);
	while (*(s1++) != '\0')
		*a++ = *s1++;
	while (*(s2++) != '\0')
		*a++ = *s2++;
	*a++ = '\0';
	return (a);
}


int main()
{
	char a[19] = "El Tour de Francia";
	char b[27] = "Es una prueba de cliclismo";

	printf("%s\n", ft_strjoin(a, b));
 }
