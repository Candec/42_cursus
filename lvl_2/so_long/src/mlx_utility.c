/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:44 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/20 17:40:55 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	calc_coord(int x, int y, t_coord *coord)
{
	coord->x = x * ASSET_SIZE;
	coord->y = y * ASSET_SIZE;
}

void	render_asset(t_mlx *data, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x, y);
}

void	win_size(t_mlx *data)
{
	data->win_width = ASSET_SIZE * data->map.width;
	data->win_height = ASSET_SIZE * data->map.height;
}

int	move_is_valid(t_mlx *data, int x, int y)
{
	if (data->map.content[y][x] == '1')
		return (ERROR);
	else if (data->map.content[y][x] == 'E'
		&& data->map.collectable != data->map.collected)
		return (ERROR);
	else if (data->map.player_escape == TRUE)
		return (ERROR);
	return (0);
}

void	previous_tile_space(t_mlx *data, t_coord *coord)
{
	data->map.content[data->map.p_y][data->map.p_x] = '0';
	calc_coord(data->map.p_x, data->map.p_y, coord);
	render_asset(data, data->img_floor_tile.img, coord->x, coord->y);
}
