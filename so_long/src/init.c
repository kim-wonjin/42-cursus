/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:51 by jinyoo            #+#    #+#             */
/*   Updated: 2022/03/17 21:27:08 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	minilibx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE, \
	game->height * TILE, "so_long");
}

static void	save_map(t_game *game, char *line, int col)
{
	int	i;

	i = 0;
	game->map[col] = (char *)malloc(sizeof(char) * game->width);
	while (line[i])
	{
		if (line[i] == 'P')
		{
			game->position.player_x = i;
			game->position.player_y = col;
		}
		game->map[col][i] = line[i];
		i++;
	}
}

void	map_init(t_game *game, int fd)
{
	char	*line;
	int		col;

	col = 0;
	game->map = (char **)malloc(sizeof(char *) * game->height);
	while (get_next_line(fd, &line) > 0)
	{
		save_map(game, line, col);
		draw_init_map(game, line, col);
		free(line);
		col++;
	}
	save_map(game, line, col);
	draw_init_map(game, line, col);
	free(line);
}

void	map_textures_init(t_game *game)
{
	game->map_textures.wall = 0;
	game->map_textures.player = 0;
	game->map_textures.exit = 0;
	game->map_textures.collectible = 0;
	game->collect = 0;
	game->move = 0;
}
