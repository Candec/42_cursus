/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:14 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/04 20:46:42 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
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
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 == NULL || s2 == NULL || !ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free((char *)s1);
	return (ptr);
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
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	r_line == NULL ? r_line = ft_calloc(1, 1) : NULL;
	r = 0;
	while (!ft_strchr(r_line, '\n'))
	{
		r = read(fd, bf, BUFFER_SIZE);
		if (r < 0)
			return (-1);
		bf[r] = '\0';
		r_line = ft_strjoin(r_line, bf);
		*line = r_line;
		if (r == 0)
			return (0);
	}
	*line = ft_substr(r_line, 0, (ft_strchr(r_line, '\n') - r_line));
	temp = r_line;
	r_line = ft_strdup(temp + (ft_strlen(*line) + 1));
	free(temp);
	return (1);
}
