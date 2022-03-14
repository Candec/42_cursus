/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:26:58 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/11 09:23:28 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *str1, char *str2, int cmp)
{
	int	i;

	i = 0;
	if (!str1 || !str2 || cmp < 0)
		return (0);
	while (i < cmp)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp_two(char *str1, char *str2)
{
	int	i;
	int	cmp;

	i = 0;
	if (!str1 || !str2)
		return (0);
	cmp = ft_min(ft_strlen(str1), ft_strlen(str2));
	while (i <= cmp)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	my_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

int	ft_strcmp_envp(char *whole_var, char *var)
{
	int	i;
	int	cmp;

	if (!whole_var || !var)
		return (0);
	i = 0;
	cmp = ft_min(ft_strlen(whole_var), ft_strlen(var));
	while (i <= cmp)
	{
		if (whole_var[i] != var[i])
		{
			if (whole_var[i] == '=' && var[i] == '\0')
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(char *haystack, char *needle)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!haystack)
		return (NULL);
	if (*needle == '\0' || needle == NULL)
		return (haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
