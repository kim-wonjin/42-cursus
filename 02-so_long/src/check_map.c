/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:47:27 by wokim             #+#    #+#             */
/*   Updated: 2022/04/15 12:39:27 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_all_map_textures(t_game *game)
{
	if (!game->map_textures.wall)
		close_game(-1, game);
	if (!game->map_textures.collectible)
		close_game(-1, game);
	if (!game->map_textures.player)
		close_game(-1, game);
	if (!game->map_textures.exit)
		close_game(-1, game);
}

static void	set_map_textures(t_game *game, char texture)
{
	if (texture == '1' && !game->map_textures.wall)
		game->map_textures.wall = 1;
	else if (texture == 'C')
		game->map_textures.collectible += 1;
	else if (texture == 'P')
	{
		if (game->map_textures.player == 1)
			close_game(-1, game);
		game->map_textures.player = 1;
	}
	else if (texture == 'E')
	{
		if (game->map_textures.exit == 1)
			close_game(-1, game);
		game->map_textures.exit = 1;
	}
}

static void	check_validate_map(t_game *game, char *line, int flag)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(line);
	while (line[++i])
	{
		if (flag && line[i] != '1')
			close_game(-1, game);
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && \
		line[i] != 'C' && line[i] != 'E')
			close_game(-1, game);
		if ((i == 0 || i == len - 1) && line[i] != '1')
			close_game(-1, game);
		if (len != game->width)
			close_game(-1, game);
		set_map_textures(game, line[i]);
	}
}

void	check_map(t_game *game, int fd)
{
	char	*line;

	game->height = 1;
	map_textures_init(game);
	while (get_next_line(fd, &line) > 0)
	{
		if (game->height == 1)
		{
			game->width = ft_strlen(line);
			check_validate_map(game, line, 1);
		}
		else
			check_validate_map(game, line, 0);
		free(line);
		game->height += 1;
	}
	check_validate_map(game, line, 1);
	free(line);
	is_all_map_textures(game);
}
