/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:44 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/13 08:53:02 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_data(t_mlx *data)
{
	int	i;

	i = 0;
	if (data->map.content != NULL)
	{
		while (data->map.content[i])
			free(data->map.content[i++]);
	}
	free(data->map.content);
	data->map.content = NULL;
}

void	handle_error(t_mlx *data, char *msg, bool stop)
{
	write(1, "Error\n", 7);
	write(1, msg, ft_strlen(msg));
	if (stop == TRUE)
	{
		clean_data(data);
		exit(EXIT_FAILURE);
	}
}
