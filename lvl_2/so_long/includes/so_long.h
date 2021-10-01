#ifndef SO_LONG
# define SO_LONG

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../libft/libft.h"


/*
** Definitons
*/
# define ERROR -1

enum
{
	FALSE,
	TRUE,
};

typedef struct	s_img

{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_map
{
	char	*fd;
	int		height;
	int		width;
	char	**content;
	bool	player;
	bool	exit;
	int		collectable;
	int		player_x;
	int		player_y;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}				t_mlx;

/*
** Functions
*/


/*
** handle_error.c
*/
void	handle_error(t_map *map, char *msg, bool stop);
void	clean_data(t_map *map);

/*
** map_valid.c
*/
void	map_valid(t_map *map);

/*
** window.c
*/
void	init_game(t_map *map);


#endif
