/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:44 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/16 21:09:50 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_hook(t_mlx *data)
{
	clean_data(data);
	mlx_destroy_image(data->mlx_ptr, data->img_floor_tile.img);
	mlx_destroy_image(data->mlx_ptr, data->img_exit_tile.img);
	mlx_destroy_image(data->mlx_ptr, data->img_wall_tile.img);
	mlx_destroy_image(data->mlx_ptr, data->img_p_d_tile.img);
	mlx_destroy_image(data->mlx_ptr, data->img_p_e_tile.img);
	mlx_destroy_image(data->mlx_ptr, data->img_p_l_tile.img);
	mlx_destroy_image(data->mlx_ptr, data->img_p_r_tile.img);
	mlx_destroy_image(data->mlx_ptr, data->img_p_u_tile.img);
	mlx_destroy_image(data->mlx_ptr, data->img_col_tile.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
	return (1);
}

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
		clean_data(data);
	exit(EXIT_FAILURE);
}
