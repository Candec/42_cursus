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
# include "../minilibx_mms_20200219/mlx.h"

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

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;


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
	int		collected;
	int		steps;
	int		p_x;
	int		p_y;
	bool	player_escape;
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
** Main
*/
void	print_map(t_mlx *data);

/*
** handle_error.c
*/
int		exit_hook(t_mlx *data);
void	handle_error(t_mlx *data, char *msg, bool stop);
void	clean_data(t_mlx *data);

/*
** map_valid.c
*/
void	map_valid(t_mlx *data);

/*
** window.c
*/
int		init_game(t_mlx *data);

/*
** texture.c
*/
int		xpm_to_image_wrapper(t_mlx *data, t_img *image, char *filename);
int		load_textures(t_mlx *data);

/*
** mlx_utilities.c
*/
void	render_asset(t_mlx *data, void *img_ptr, int x, int y);
void	calc_coord(int x, int y, t_coord *coord);
void	win_size(t_mlx *data);
int		move_is_valid(t_mlx *data, int x, int y);
void	previous_tile_space(t_mlx *data, t_coord *coord);


/*
** move.c
*/
void	move(t_mlx *data, int key);

#endif
