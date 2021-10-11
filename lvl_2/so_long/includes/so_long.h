/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:26 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/07 13:03:26 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define ASSET_SIZE 64

enum
{
	FALSE,
	TRUE,
};

typedef struct	s_img

{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_height;
	int		img_width;
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
	t_img	img_floor_tile;
	t_img	img_wall_tile;
	t_img	img_exit_tile;
	t_img	img_col_tile;
	t_img	img_p_u_tile;
	t_img	img_p_d_tile;
	t_img	img_p_r_tile;
	t_img	img_p_l_tile;
	t_img	img_p_e_tile;
	t_map	map;
	int	win_width;
	int	win_height;
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
int	init_game(t_map *map);


#endif
