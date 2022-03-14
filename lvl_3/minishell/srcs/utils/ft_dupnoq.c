/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupnoq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:32:45 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/10 19:39:20 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_quoted(char *s, char *sub, int i, int x);

char	*ft_dupnoq(char *s)
{
	int		i;
	char	*sub;
	char	*temp;

	if (!s)
		return (NULL);
	sub = malloc_or_exit((ft_strlen(s) + 1) * sizeof(char));
	i = handle_quoted(s, sub, 0, 0);
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
	{
		free(sub);
		return (NULL);
	}
	while (i >= 0)
	{
		temp[i] = sub[i];
		i--;
	}
	free(sub);
	free(s);
	return (temp);
}

static int	handle_quoted(char *s, char *sub, int i, int x)
{
	int	inhib;

	inhib = 0;
	while (s[x] != '\0')
	{
		if (s[x] == '\'')
		{
			if (!update_inhib(&inhib, 1))
				sub[i++] = s[x];
		}
		else if (s[x] == '\"')
		{
			if (!update_inhib(&inhib, 2))
				sub[i++] = s[x];
		}
		else
			sub[i++] = s[x];
		x++;
	}
	sub[i] = '\0';
	return (i);
}

int	update_inhib(int *inhib, int mode)
{
	if (mode == 1)
	{
		if (*inhib == 0)
			*inhib = 1;
		else if (*inhib == 1)
			*inhib = 0;
		else
			return (0);
	}
	else
	{
		if (*inhib == 0)
			*inhib = 2;
		else if (*inhib == 2)
			*inhib = 0;
		else
			return (0);
	}
	return (1);
}
