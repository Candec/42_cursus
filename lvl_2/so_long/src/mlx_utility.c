/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:44 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/16 20:55:37 by jibanez-         ###   ########.fr       */
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
	data->win_height = ASSET_SIZE * (1 + data->map.height);
}
