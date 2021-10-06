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

void	win_size(t_mlx *data)
{
	data->win_width = ASSET_SIZE * data->map.width;
	data->win_height = ASSET_SIZE * data->map.height;
}

int	start_mlx_and_window(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		//handle_error(&data->map, "MLX_ERROR", TRUE);
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "Game");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		//handle_error(&data->&map, "WIN_ERROR", TRUE);
		return (1);
	}
	return (0);
}

void	init_game(t_map *map)
{
	t_mlx	data;

	data.map = *map;
	// data.img.addr = ft_strdup("./Assets/tile.xpm");
	// data.img.line_len = ASSET_SIZE;
	win_size(&data);
	start_mlx_and_window(&data);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, ASSET_SIZE, ASSET_SIZE);
	// mlx_xpm_file_to_image(data.mlx_ptr, data.img.addr, &data.img.line_len, &data.img.line_len);
	
	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
