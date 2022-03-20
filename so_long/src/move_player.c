/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:48:55 by jinyoo            #+#    #+#             */
/*   Updated: 2022/03/18 20:51:31 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
	{
		game->collect += 1;
		game->map[y][x] = '0';
	}
	if (game->map[y][x] == 'E')
	{
		if (game->collect == game->map_textures.collectible)
			close_game(0, game);
	}
	return (1);
}

static int	move_player_handler(int keycode, t_game *game)
{
	int	x;
	int	y;
	int	flag;

	x = game->position.player_x;
	y = game->position.player_y;
	if (keycode == KEY_W)
		y--;
	else if (keycode == KEY_S)
		y++;
	else if (keycode == KEY_A)
		x--;
	else if (keycode == KEY_D)
		x++;
	flag = check_move(game, x, y);
	if (flag)
	{
		if (game->map[game->position.player_y][game->position.player_x] \
		== 'E')
			flag = 2;
		game->position.player_x = x;
		game->position.player_y = y;
	}
	return (flag);
}

static void	passing_exit(t_game *game, int prev_x, int prev_y)
{
	draw_texture(game, 'e');
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->img.img_ptr, prev_x, prev_y);
}

int	move_player(int keycode, t_game *game)
{
	int	prev_x;
	int	prev_y;
	int	flag;

	if (keycode == KEY_ESC)
		close_game(2, game);
	flag = move_player_handler(keycode, game);
	if (flag)
	{
		prev_x = game->position.tile_x;
		prev_y = game->position.tile_y;
		if (keycode == KEY_W)
			game->position.tile_y -= TILE;
		else if (keycode == KEY_S)
			game->position.tile_y += TILE;
		else if (keycode == KEY_A)
			game->position.tile_x -= TILE;
		else if (keycode == KEY_D)
			game->position.tile_x += TILE;
		draw_updated_player(game, prev_x, prev_y);
		if (flag == 2)
			passing_exit(game, prev_x, prev_y);
		printf("Move : %d\n", game->move);
	}
	return (0);
}
