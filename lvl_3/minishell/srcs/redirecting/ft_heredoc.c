/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:14:15 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/11 09:32:20 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_until(char *str);
static char	*keep_getting_hd(char *holder);

char	*ft_heredoc(t_comm *comm)
{
	int		temp;
	char	*str;
	char	*t;

	t = ft_strdup(".mini.thd");
	if (!t)
		return (0);
	temp = open(t, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (temp < 0)
		return (0);
	str = get_until(comm->heredoc_word);
	if (!str)
		return (0);
	write(temp, str, ft_strlen(str) * sizeof(char));
	free(str);
	close(temp);
	return (t);
}

static char	*get_until(char *str)
{
	char	*holder;
	char	*needle;
	int		i;

	i = 0;
	holder = readline("> ");
	if (!holder)
		return (NULL);
	if (ft_isspace(str[ft_strlen(str) - 1]))
		str[ft_strlen(str) - 1] = '\0';
	needle = ft_strnstr(holder, str);
	while (!needle)
	{
		i = 1;
		holder = keep_getting_hd(holder);
		if (!holder)
			return (NULL);
		needle = ft_strnstr(holder, str);
	}
	if (i && needle[0] != '\0')
		needle[0] = '\0';
	return (holder);
}

static char	*keep_getting_hd(char *holder)
{
	char	*temp;
	char	*o_temp;

	o_temp = readline("> ");
	temp = ft_strcat(holder, "\n");
	free(holder);
	if (!temp)
		return (NULL);
	holder = ft_strcat(temp, o_temp);
	free(o_temp);
	free(temp);
	if (!holder)
		return (NULL);
	return (holder);
}
