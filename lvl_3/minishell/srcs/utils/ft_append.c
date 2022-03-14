/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:25:49 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/11 08:43:49 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *str, char *append)
{
	int		size;
	int		i;
	char	*holder;

	if (!append)
		return (ft_strdup(str));
	size = ft_strlen(str) + ft_strlen(append);
	i = 0;
	holder = (char *)malloc(sizeof(char) * (size + 1));
	if (!holder)
		return (0);
	while (i < size)
	{
		while (*str != '\0')
			holder[i++] = *str++;
		while (*append != '\0')
			holder[i++] = *append++;
	}
	holder[i] = '\0';
	return (holder);
}

char	*ft_append(char *str, char *append)
{
	int		size;
	int		i;
	char	*holder;

	size = ft_strlen(str) + ft_strlen(append);
	i = 0;
	holder = (char *)malloc(sizeof(char) * (size + 2));
	if (!holder)
		return (0);
	while (i < size)
	{
		while (*str != '\0')
			holder[i++] = *str++;
		holder[i++] = '/';
		while (*append != '\0')
			holder[i++] = *append++;
	}
	holder[i] = '\0';
	return (holder);
}
