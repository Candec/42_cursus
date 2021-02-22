/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:14 by jibanez-          #+#    #+#             */
/*   Updated: 2021/02/21 20:07:46 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	ssize_t	i;

	new = malloc(ft_strlen(str));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	return (new);
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
	char	*a;
	char	*b;

	size = ft_strlen(s1) + ft_strlen(s2) - 1;
	a = malloc(size * sizeof(char *));
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

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFFER_SIZE];
	static char	*r_line;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (r_line == NULL)
		r_line = malloc(0);
	while (!ft_strchr(r_line, '\n'))
	{
		r = read(fd, bf, BUFFER_SIZE);
		if (r <= 0)
			break ;
		bf[r] = '\0';
		r_line = ft_strjoin(r_line, bf);
	}
	if (r == 0)
		return (0);
	else if (r < 0)
		return (-1);
	*line = ft_substr(r_line, 0, (ft_strchr(r_line, '\n') - r_line));
	r_line = ft_strdup(r_line + (ft_strlen(*line) + 1));
	return (1);
}
