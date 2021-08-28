/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:14 by jibanez-          #+#    #+#             */
/*   Updated: 2021/05/17 11:06:06 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static void	final_line(char **content, char **line)
{
	int	i;

	i = 0;
	*line = ft_strdup(content[i]);
	free(content[i]);
	content[i] = 0;
}

static int	save_line(char **content, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*content)[i] != '\0' && (*content)[i] != '\n')
		i++;
	if (ft_strchr(*content, '\n'))
	{
		*line = ft_substr(*content, 0, i);
		tmp = ft_strdup(ft_strchr(*content, '\n') + 1);
		free(*content);
		*content = tmp;
		return (1);
	}
	else
		return (0);
}

static void	store(char **content, char *bf)
{
	char	*tmp;

	tmp = 0;
	if (!(*content))
		*content = ft_strdup(bf);
	else
	{
		tmp = *content;
		*content = ft_strjoin(tmp, bf);
		free(tmp);
	}
}

int	ft_get_next_line(int fd, char **line)
{
	static char	*content[100];
	ssize_t		r;
	char		bf[BUFFER_SIZE + 1];

	if (read(fd, 0, 0) == -1 || fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (content[fd] && save_line(&content[fd], line))
		return (1);
	r = read(fd, bf, BUFFER_SIZE);
	while (r > 0)
	{
		bf[r] = '\0';
		store(&content[fd], bf);
		if (save_line(&content[fd], line))
			return (1);
		r = read(fd, bf, BUFFER_SIZE);
	}
	if (content[fd] && !ft_strchr(content[fd], '\n'))
	{
		final_line(&content[fd], line);
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
