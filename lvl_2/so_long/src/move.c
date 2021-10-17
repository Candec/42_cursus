/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:56:55 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/18 00:43:46 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_is_valid(t_mlx *data, int x, int y)
{
	if (data->map.content[y][x] == '1')
		return (ERROR);
	else if (data->map.content[y][x] == 'E'
		&& data->map.collectable != data->map.collected)
		return (ERROR);
	return (0);
}

void	move_up(t_mlx *data)
{
	t_coord *coord;
	
	if (move_is_valid(data, data->map.player_x, data->map.player_y - 1) != -1)
	{
		data->map.content[data->map.player_y][data->map.player_x] = '0';
		data->map.content[data->map.player_y - 1][data->map.player_x] = 'P';
		data->map.player_y -= 1;
		calc_coord(data->map.player_x, data->map.player_y, coord);
		render_asset(data, data->img_p_u_tile.img, coord->x, coord->y);
	}
}

void	move_down(t_mlx *data)
{
	if (move_is_valid(data, data->map.player_x, data->map.player_y + 1) != -1)
	{
		data->map.content[data->map.player_y][data->map.player_x] = '0';
		data->map.content[data->map.player_y + 1][data->map.player_x] = 'P';
		data->map.player_y += 1;
	}
}

void	move_left(t_mlx *data)
{
	if (move_is_valid(data, data->map.player_x - 1, data->map.player_y) != -1)
	{
		data->map.content[data->map.player_y][data->map.player_x] = '0';
		data->map.content[data->map.player_y][data->map.player_x - 1] = 'P';
		data->map.player_x -= 1;
	}
}

void	move_right(t_mlx *data)
{
	if (move_is_valid(data, data->map.player_x + 1, data->map.player_y) != -1)
	{
		data->map.content[data->map.player_y][data->map.player_x] = '0';
		data->map.content[data->map.player_y][data->map.player_x + 1] = 'P';
		data->map.player_x += 1;
	}
}

void	move(t_mlx *data, int key)
{
	if (key == XK_Up)
		move_up(data);
	else if (key == XK_Down)
		move_down(data);
	else if (key == XK_Left)
		move_left(data);
	else if (key == XK_Right)
		move_right(data);
	printf("x: %d - y: %d\n", data->map.player_x, data->map.player_y);
	print_map(data);
}