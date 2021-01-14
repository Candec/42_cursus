/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:14 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/24 10:48:14 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	get_next_line(int fd, char **line)
{
	static char	*c_line = NULL;
	ssize_t		r;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	c_line == NULL ? c_line = ft_strnew(0) : NULL;
	while (!ft_strchr(c_line, '\n') && (r = read(fd, bf, BUFFER_SIZE) > 0)
}
