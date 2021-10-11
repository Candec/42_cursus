/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:49 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/11 13:45:09 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_alloc(t_map *map)
{
	int		i;
	int		fd;
	char	*line;
	char	**lines;

	i = 0;
	fd = open(map->fd, O_RDONLY);
	lines = ft_calloc(map->height, map->width);
	if (!lines)
		handle_error(map, "MALLOC ERROR", TRUE);
	while (ft_get_next_line(fd, &line) == 1)
		lines[i++] = line;
	lines[i] = line;
	map->content = lines;
	close(fd);
}

void	map_size(t_map *map)
{
	int		fd;
	char	*line;
	int		temp;

	temp = 0;
	fd = open(map->fd, O_RDONLY);
	while (ft_get_next_line(fd, &line) == 1)
	{
		if (!temp)
			map->width = ft_strlen(line);
		temp = ft_strlen(line);
		if (map->width != temp)
		{
			free(line);
			close(fd);
			handle_error(map, "DIMENSION NOT CORRECT", TRUE);
		}
		map->height++;
		free(line);
	}
	free(line);
	close(fd);
}

void	init_map(t_map *map, char*file)
{
	map->height = 0;
	map->width = -1;
	map->fd = file;
	if (!map->fd)
		handle_error(map, "CANT OPEN FILE", TRUE);
	map->player = FALSE;
	map->exit = FALSE;
	map->collectable = 0;
}

int	main(int argc, char *argv[])
{
	t_map	map;
	void	*mlx;
	void	*mlx_win;

	if (argc != 2)
		handle_error(&map, "ARGUMENTS", TRUE);
	init_map(&map, argv[1]);
	map_size(&map);
	map_alloc(&map);
	map_valid(&map);
	if (init_game(&map) == ERROR)
		return (ERROR);


	// printf("Player Status: %d\n", map.player);
	// printf("Player coordinates x:%d - y:%d\n", map.player_x, map.player_y);
	// printf("Exit Status: %d\n", map.exit);
	// printf("Number of collectable: %d\n", map.collectable);
	clean_data(&map);
	return (0);
}
