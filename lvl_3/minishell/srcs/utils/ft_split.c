/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:25:30 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/15 16:26:30 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static char		*ft_split_substr(char const *str, char c, int offset);
static int		ft_count_str(char const *str, char c);
static char		**ft_split2(char const *str, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || s[1] == '\0')
	{
		split = malloc(sizeof(char *));
		if (!split)
			return (NULL);
		split[0] = 0;
		return (split);
	}
	split = ft_split2(s, c);
	return (split);
}

static char	**ft_split2(char const *str, char c)
{
	char	**split;
	int		i;
	int		inword;
	int		j;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (ft_count_str(str, c) + 1));
	if (!split)
		return (NULL);
	inword = 0;
	while (str[i] != '\0')
	{
		if (inword == 0 && str[i] != c)
			split[j++] = ft_split_substr(str, c, i);
		if (str[i] == c)
			inword = 0;
		else
			inword = 1;
		i++;
	}
	split[j] = 0;
	return (split);
}

static char	*ft_split_substr(char const *str, char c, int offset)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (str[offset + i] != c && str[offset + i] != '\0')
		i++;
	sub = malloc(i + 1);
	if (!sub)
		return (NULL);
	j = 0;
	while (j < i && str[offset] != '\0')
	{
		sub[j] = str[offset];
		offset++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

static int	ft_count_str(char const *str, char c)
{
	int	i;
	int	inword;
	int	words;

	i = 0;
	inword = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (inword == 1)
				words++;
			inword = 0;
		}
		else
			inword = 1;
		i++;
	}
	if (str[i] == '\0' && inword == 1)
		words++;
	return (words);
}
