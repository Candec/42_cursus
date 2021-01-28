/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:14 by jibanez-          #+#    #+#             */
/*   Updated: 2021/01/28 20:56:25 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	ssize_t	i;

	new = ft_strnew(ft_strlen(str));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*a;
	char	*b;

	size = ft_strlen(s1) + ft_strlen(s2) - 1;
	a = malloc(size);
	b = a;
	while (*(s1) != '\0')
	{
		*a = *s1;
		a++;
		s1++;
	}
	while (*(s2) != '\0')
	{
		*a = *s2;
		a++;
		s2++;
	}
	a = '\0';
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s || (long int)len < 0)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFFER_SIZE + (r = 1)];
	static char	*sline[FD_SIZE];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	sline[fd] == NULL ? sline[fd] = ft_strnew(0) : NULL;
	while (!ft_strchr(sline[fd], '\n') && (r = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[r] = '\0';
		tmp = ft_strjoin(sline[fd], bf);
		ft_memdel((void **)&sline[fd]);
		sline[fd] = tmp;
	}
	if (r == 0)
		*line = ft_strdup(sline[fd]);
	else if (r > 0)
		*line = ft_substr(sline[fd], 0, (ft_strchr(sline[fd], '\n') - sline[fd]));
	else
		return (-1);
	tmp = ft_strdup(sline[fd] + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));
	ft_memdel((void **)&sline[fd]);
	sline[fd] = tmp;
	return (r == 0 ? 0 * ft_memdel((void **)&sline[fd]) : 1);
}
