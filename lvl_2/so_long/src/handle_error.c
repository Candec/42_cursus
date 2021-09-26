#include "so_long.h"

void	clean_data(t_map *map)
{
	int	i;

	i = 0;
	if (map->content != NULL)
	{
		while (map->content[i])
			free(map->content[i++]);
	}
	free(map->content);
	map->content = NULL;
}

void	handle_error(t_map *map, char *msg, bool stop)
{
	write(1, "Error\n", 7);
	write(1, msg, ft_strlen(msg));
	if (stop == TRUE)
	{
		clean_data(map);
		exit(EXIT_FAILURE);
	}
}
