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

void	init_game(t_map *map)
{
	t_mlx data;

	data.map = *map;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
		// handle_error(map, "MLX_ERROR", TRUE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "Game");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
		// handle_error(map, "WIN_ERROR", TRUE);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);


	mlx_loop(data.mlx_ptr);


	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}