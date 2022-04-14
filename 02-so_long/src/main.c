/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:50:46 by wokim             #+#    #+#             */
/*   Updated: 2022/04/14 18:25:39 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	closed(t_game *game)
{
	int	i;

	i = -1;
	printf("End Game!\n");
	while (++i < game->height)
		free(game->map[i]);
	free(game->map);
	mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	exit(0);
}

int	close_game(int flag, t_game *game)
{
	int	i;

	i = -1;
	if (flag == -1)
		printf("Error: Invalid Map\n");
	else if (flag == 0)
		printf("Good Game!\n");
	else
		printf("End Game!\n");
	if (flag != -1)
	{
		while (++i < game->height)
			free(game->map[i]);
		free(game->map);
		mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_game		game;
	int			fd;

	if (argc != 2)
	{
		printf("[Usage] -> ./so_long {map_file_name.ber}\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	check_map(&game, fd);
	minilibx_init(&game);
	fd = open(argv[1], O_RDONLY);
	map_init(&game, fd);
	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &move_player, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_EXIT, 0, &closed, &game);
	mlx_loop(game.mlx_ptr);
}
