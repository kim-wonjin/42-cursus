/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:03:57 by jinyoo            #+#    #+#             */
/*   Updated: 2022/03/18 18:18:53 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/include/get_next_line.h"
# include "minilibx_opengl_20191021/mlx.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TILE 60

typedef struct s_position
{
	int		tile_x;
	int		tile_y;
	int		player_x;
	int		player_y;
	void	*img_ptr;
}	t_position;

typedef struct s_map
{
	int	wall;
	int	player;
	int	collectible;
	int	exit;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int			collect;
	int			move;
	t_img		img;
	t_position	position;
	t_map		map_textures;
	char		**map;
}	t_game;

int		close_game(int flag, t_game *game);

void	minilibx_init(t_game *game);
void	map_init(t_game *game, int fd);
void	map_textures_init(t_game *game);

int		move_player(int keycode, t_game *game);

void	draw_init_map(t_game *game, char *line, int col);
void	draw_texture(t_game *game, char texture);
void	draw_updated_player(t_game *game, int prev_x, int prev_y);

void	check_map(t_game *game, int fd);
#endif
