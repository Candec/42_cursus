/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:00:01 by jibanez-          #+#    #+#             */
/*   Updated: 2021/11/29 17:54:03 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_mlx *data)
{
	if (keysym == 53)
		exit_hook(data);
	if (data->map.player_escape == TRUE)
		return (0);
	else if (keysym == 13 || keysym == 1
		|| keysym == 2 || keysym == 0)
		move(data, keysym);
	return (0);
}

void	draw_first_map(t_mlx *data)
{
	int		column;
	int		row;
	t_img	*tile;
	t_coord	coord;

	row = -1;
	while (++row < data->map.height)
	{
		column = -1;
		while (++column < data->map.width)
		{
			calc_coord(column, row, &coord);
			if (data->map.content[row][column] == '1')
				tile = &data->img_wall_tile;
			else if (data->map.content[row][column] == '0')
				tile = &data->img_floor_tile;
			else if (data->map.content[row][column] == 'P')
				tile = &data->img_p_d_tile;
			else if (data->map.content[row][column] == 'E')
				tile = &data->img_exit_tile;
			else if (data->map.content[row][column] == 'C')
				tile = &data->img_col_tile;
			render_asset(data, tile->img, coord.x, coord.y);
		}
	}
}

int	start_mlx_and_window(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "Game");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (ERROR);
	}
	return (0);
}

int	init_game(t_mlx *data)
{
	win_size(data);
	print_map(data);
	if (start_mlx_and_window(data) == ERROR)
		handle_error(data, "COULDN'T FIND SCREEN\n", TRUE);
	if (load_textures(data) == ERROR)
		handle_error(data, "ERROR LOADING THE IMGs\n", TRUE);
	draw_first_map(data);
	mlx_hook(data->win_ptr, 02, 1L << 2, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), &exit_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
