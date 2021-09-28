#include "../includes/so_long.h"

static void	map_collectable(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == 'C')
				map->collectable++;
			j++;
		}
		i++;
	}
	if (map->collectable == FALSE)
		handle_error(map, "NO COLLECTABLES", TRUE);
}

static void	map_exit(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == 'E' && map->exit == FALSE)
				map->exit = TRUE;
			j++;
		}
		i++;
	}
	if (map->exit == FALSE)
		handle_error(map, "NO EXIT", TRUE);
}

static void	map_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == 'P' && map->player == FALSE)
			{
				map->player = TRUE;
				map->player_x = j;
				map->player_y = i;
			}
			else if (map->content[i][j] == 'P' && map->player == TRUE)
				handle_error(map, "MORE THAN TWO PLAYERS", TRUE);
			j++;
		}
		i++;
	}
	if (map->player == FALSE)
		handle_error(map, "NO PLAYER", TRUE);
}

static void	map_walled(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	j = -1;
	x = map->height;
	y = map->width;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((i == 0 || i == x)
				&& (map->content[0][j] != '1' || map->content[x][j] != '1'))
				handle_error(map, "WALLS ARE NOT COMPLETE", TRUE);
			if ((i > 0 && i < x)
				&& (map->content[i][0] != '1' || map->content[i][y - 1] != '1'))
				handle_error(map, "WALLS ARE NOT COMPLETE", TRUE);
			j++;
		}
		i++;
	}
}

void	map_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] != '1'
				&& map->content[i][j] != '0'
				&& map->content[i][j] != 'P'
				&& map->content[i][j] != 'C'
				&& map->content[i][j] != 'E')
				handle_error(map, "INVALID SIMBOL", TRUE);
			j++;
		}
		i++;
	}
	map_walled(map);
	map_player(map);
	map_exit(map);
	map_collectable(map);
}
