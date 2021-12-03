/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:49 by jibanez-          #+#    #+#             */
/*   Updated: 2021/12/03 10:30:58 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_mlx *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	printf("\e[1;1H\e[2J");
	printf("x: %d - y: %d\n""collecables: %d\ncollected: %d\nNum of steps: %d\n",
		data->map.p_x, data->map.p_y, data->map.collectable,
		data->map.collected, data->map.steps);
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			write(1, &data->map.content[i][j], 1);
			write(1, " ", 2);
		}
		write(1, "\n", 2);
	}
	write(1, "\n", 2);
}

void	map_alloc(t_mlx *data)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;

	i = 0;
	fd = open(data->map.fd, O_RDONLY);
	data->map.content = ft_calloc(data->map.height, data->map.width);
	if (!data->map.content)
		handle_error(data, "MALLOC ERROR\n", TRUE);
	ret = 1;
	while (ret > 0)
	{
		ret = ft_get_next_line(fd, &line);
		data->map.content[i++] = line;
	}
	close(fd);
}

void	map_size(t_mlx *data)
{
	int		n;
	int		fd;
	int		ret;
	char	*line;

	fd = open(data->map.fd, O_RDONLY);
	if (fd == ERROR)
		handle_error(data, "CAN'T OPEN THE FILE\n", FALSE);
	ret = 1;
	while (ret > 0)
	{
		ret = ft_get_next_line(fd, &line);
		if (data->map.height == -1)
			data->map.width = ft_strlen(line);
		n = ft_strlen(line);
		data->map.height++;
		if (data->map.width != n)
			handle_error(data, "DIMENSION NOT CORRECT\n", FALSE);
		free(line);
		line = NULL;
	}
	data->map.height++;
	close(fd);
}

void	init_map(t_mlx *data, char*file)
{
	data->map.height = -1;
	data->map.width = -1;
	data->map.fd = file;
	if (!data->map.fd)
		handle_error(data, "CANT FIND THE FILE\n", TRUE);
	data->map.player = FALSE;
	data->map.exit = FALSE;
	data->map.player_escape = FALSE;
	data->map.collectable = 0;
	data->map.collected = 0;
}

int	main(int argc, char *argv[])
{
	t_mlx	data;

	if (argc != 2)
		handle_error(&data, "ARGUMENTS\n", FALSE);
	init_map(&data, argv[1]);
	map_size(&data);
	map_alloc(&data);
	map_valid(&data);
	if (init_game(&data) == ERROR)
		return (ERROR);
	clean_data(&data);
	return (0);
}
