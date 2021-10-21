/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:49 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/18 18:09:48 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\e[1;1H\e[2J");
	while (i <= data->map.height)
	{
		j = 0;
		while (j <= data->map.width)
		{
			write(1, &data->map.content[i][j], 1);
			write(1, " ", 2);
			j++;
		}
		write(1, "\n", 2);
		i++;
	}
	write(1, "\n", 2);
}

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
	int		n;

	fd = open(data->map.fd, O_RDONLY);
	if (fd == ERROR)
		handle_error(data, "CAN'T OPEN THE FILE", FALSE);
	while (ft_get_next_line(fd, &line) != 0)
	{
		if (data->map.height == 0)
			data->map.width = ft_strlen(line);
		n = ft_strlen(line);
		data->map.height++;
		free(line);
		if (data->map.width != n)
		{
			close(fd);
			handle_error(data, "DIMENSION NOT CORRECT", FALSE);
		}
	}
	n = ft_strlen(line);
	free(line);
	close(fd);
	if (data->map.width != n)
		handle_error(data, "DIMENSION NOT CORRECT", FALSE);
}

void	init_map(t_mlx *data, char*file)
{
	data->map.height = 0;
	data->map.width = -1;
	data->map.fd = file;
	if (!data->map.fd)
		handle_error(data, "CANT FIND THE FILE", TRUE);
	data->map.player = FALSE;
	data->map.exit = FALSE;
	data->map.player_escape = FALSE;
	data->map.collectable = 0;
	data->map.collected = 0;
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
	if (init_game(&data) == ERROR)
		return (ERROR);
	clean_data(&data);
	return (0);
}
