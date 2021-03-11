/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:14 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/11 14:18:41 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		save_line(char **content, char **line)
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

void	store(char **content, char *bf)
{
	char *tmp;

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

int		get_next_line(int fd, char **line)
{
	static char	*content[100];
	ssize_t		r;
	char		bf[BUFFER_SIZE + 1];

	if (read(fd, 0, 0) == -1 || fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (content[fd] && save_line(&content[fd], line))
		return (1);
	while ((r = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[r] = '\0';
		store(&content[fd], bf);
		if (save_line(&content[fd], line))
			return (1);
	}
	if (content[fd] && !ft_strchr(content[fd], '\n'))
	{
		*line = ft_strdup(content[fd]);
		free(content[fd]);
		content[fd] = 0;
		return (0);
	}
	if ((r = read(fd, bf, BUFFER_SIZE)) == 0 && !(content[fd]))
		*line = ft_strdup("");
	return (0);
}
