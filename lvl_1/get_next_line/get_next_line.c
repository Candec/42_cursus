/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:14 by jibanez-          #+#    #+#             */
/*   Updated: 2021/02/24 16:05:02 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_strlen(src) * sizeof(*dest));
	if (dest == '\0')
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


int	get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFFER_SIZE];
	static char	*r_line;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (r_line == NULL)
		r_line = malloc(0);
	while (!ft_strchr(r_line, '\n'))
	{
		r = read(fd, bf, BUFFER_SIZE);
		bf[r] = '\0';
		r_line = ft_strjoin(r_line, bf);
		if (r == 0)
		{
			*line = r_line;
			return (0);
		}
	}
	*line = ft_substr(r_line, 0, (ft_strchr(r_line, '\n') - r_line));
	if (r < 0)
		return (-1);
	r_line = ft_strdup(r_line + (ft_strlen(*line) + 1));
	return (1);
}
