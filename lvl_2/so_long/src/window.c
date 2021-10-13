/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:00:01 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/13 18:02:33 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	render(t_mlx *data)
{
	if (data->win_ptr == NULL)
		return (1);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 960, 540, 0xFF0000);
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
	if (!data->img_floor_tile.img || !data->img_wall_tile.img
		|| !data->img_col_tile.img || !data->img_p_e_tile.img
		|| !data->img_p_l_tile.img || !data->img_p_r_tile.img
		|| !data->img_p_u_tile.img || !data->img_p_d_tile.img)
		return (ERROR);
	return (1);
}

void	draw_first_map(t_mlx *data)
{
	int		column;
	int		row;
	t_img	*tile;

	column = -1;
	row = -1;

	while (++row <= data->map.width)
	{
		column = -1;
		while (++column <= data->map.height)
		{
			if (data->map.content[row][column] == '1')
				tile = &data->img_wall_tile;
			else if (data->map.content[row][column] == '0')
				tile = &data->img_exit_tile;
			else if (data->map.content[row][column] == 'P')
				tile = &data->img_p_d_tile;
			else if (data->map.content[row][column] == 'E')
				tile = &data->img_exit_tile;
			else if (data->map.content[row][column] == 'C')
				tile = &data->img_col_tile;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, tile->img, row , column);
		}

	}
}

// int	render(t_mlx *data)
// {
// 	if (data->win_ptr == NULL)
// 		return (1);
// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 960, 540, 0xFF0000);
// 	return (0);
// }

void	win_size(t_mlx *data)
{
	data->win_width = ASSET_SIZE * data->map.width;
	data->win_height = ASSET_SIZE * (1 + data->map.height);
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
	// data.img.addr = ft_strdup("./Assets/tile.xpm");
	// data.img.line_len = ASSET_SIZE;
	win_size(data);
	if (start_mlx_and_window(data) == ERROR)
	{
		write(1, "COULDN'T FIND SCREEN\n", 22);
		return (ERROR);
	}
	if (load_textures(data) == ERROR)
	{
		write(1, "ERROR LOADING THE IMGs\n", 24);
		return (ERROR);
	}
	draw_first_map(data);
	// mlx_loop_hook(data->mlx_ptr, &render, data);
	// mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, ASSET_SIZE, ASSET_SIZE);
	// mlx_xpm_file_to_image(data.mlx_ptr, data.img.addr, &data.img.line_len, &data.img.line_len);
	
	mlx_loop(data->mlx_ptr);

	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}
