/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:42:04 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/17 15:53:15 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_images_loaded(t_mlx *data)
{
	if (!data->img_floor_tile.img || !data->img_wall_tile.img
		|| !data->img_col_tile.img || !data->img_p_e_tile.img
		|| !data->img_p_l_tile.img || !data->img_p_r_tile.img
		|| !data->img_p_u_tile.img || !data->img_p_d_tile.img)
		return (ERROR);
	return (0);
}

int	xpm_to_image_wrapper(t_mlx *data, t_img *image, char *filename)
{
	image->img = mlx_xpm_file_to_image(data->mlx_ptr,
			filename, &image->img_width, &image->img_height);
	if (!image->img)
		return (ERROR);
	return (1);
}

int	load_textures(t_mlx *data)
{
	xpm_to_image_wrapper(data, &data->img_floor_tile,
		"./assets/floor.xpm");
	xpm_to_image_wrapper(data, &data->img_exit_tile,
		"./assets/exit.xpm");
	xpm_to_image_wrapper(data, &data->img_wall_tile,
		"./assets/wall.xpm");
	xpm_to_image_wrapper(data, &data->img_col_tile,
		"./assets/collect.xpm");
	xpm_to_image_wrapper(data, &data->img_p_d_tile,
		"./assets/char_d.xpm");
	xpm_to_image_wrapper(data, &data->img_p_u_tile,
		"./assets/char_up.xpm");
	xpm_to_image_wrapper(data, &data->img_p_l_tile,
		"./assets/char_left.xpm");
	xpm_to_image_wrapper(data, &data->img_p_r_tile,
		"./assets/char_right.xpm");
	xpm_to_image_wrapper(data, &data->img_p_e_tile,
		"./assets/char_exit.xpm");
	if (check_images_loaded(data) == ERROR)
		return (ERROR);
	return (1);
}
