/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:49 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/13 14:32:35 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_alloc(t_mlx *data)
{
	int		i;
	int		fd;
	char	*line;
	char	**lines;

	i = 0;
	fd = open(data->map.fd, O_RDONLY);
	lines = ft_calloc(data->map.height, data->map.width);
	if (!lines)
		handle_error(data, "MALLOC ERROR", TRUE);
	while (ft_get_next_line(fd, &line) == 1)
		lines[i++] = line;
	lines[i] = line;
	data->map.content = lines;
	close(fd);
}

void	map_size(t_mlx *data)
{
	int		fd;
	char	*line;
	int		temp;

	temp = 0;
	fd = open(data->map.fd, O_RDONLY);
	while (ft_get_next_line(fd, &line) == 1)
	{
		if (!temp)
			data->map.width = ft_strlen(line);
		temp = ft_strlen(line);
		if (data->map.width != temp)
		{
			free(line);
			close(fd);
			handle_error(data, "DIMENSION NOT CORRECT", TRUE);
		}
		data->map.height++;
		free(line);
	}
	free(line);
	close(fd);
}

void	init_map(t_mlx *data, char*file)
{
	data->map.height = 0;
	data->map.width = -1;
	data->map.fd = file;
	if (!data->map.fd)
		handle_error(data, "CANT OPEN FILE", TRUE);
	data->map.player = FALSE;
	data->map.exit = FALSE;
	data->map.collectable = 0;
}

int	main(int argc, char *argv[])
{
	t_mlx	data;
	void	*mlx;
	void	*mlx_win;

	if (argc != 2)
		handle_error(&data, "ARGUMENTS", TRUE);
	init_map(&data, argv[1]);
	map_size(&data);
	map_alloc(&data);
	map_valid(&data);
	int i = 0;
	int j = 0;
	while (i <= data.map.height)
	{
		j = 0;
		while (j <= data.map.width)
		{
			printf("%c ", data.map.content[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	if (init_game(&data) == ERROR)
		return (ERROR);


	// printf("Player Status: %d\n", map.player);
	// printf("Player coordinates x:%d - y:%d\n", map.player_x, map.player_y);
	// printf("Exit Status: %d\n", map.exit);
	// printf("Number of collectable: %d\n", map.collectable);
	clean_data(&data);
	return (0);
}
