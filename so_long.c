/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:58:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/09 16:28:56 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_map	map_attributes;
	char	**map;
	
	fd = primitive_errors(argc, argv);
	if (fd == -1)
		return (0);
	map_attributes = init_map_attributes();
	map = check_map(fd, &map_attributes);
	if (map == NULL)
		return (0);
	init_game(map, &map_attributes);
	return (0);
}

void	init_game(char **map, t_map *map_attributes)
{
	t_game	game;

	game.id = mlx_init();
	game.window = mlx_new_window(game.id, map_attributes->col * SPRITE_SIZE, \
	map_attributes->row * SPRITE_SIZE + 64, "HARRY POTTER - SO_LONG");
	game.sprites = init_sprites(&game);
	game.frames = 1;
	game.collect = map_attributes->collect;
	game.map = map;
	game.map_attributes = map_attributes;
	display_map(&game, game.map, game.map_attributes);
	mlx_loop_hook(game.id, update_game, &game);
	mlx_key_hook(game.window, key_hook, &game);
	mlx_hook(game.window, 17, 0, end_game, &game);
	mlx_loop(game.id);
}

int	update_game(t_game *game)
{
	game->frames++;
	check_game(game);
	//	update_score(game);
	display_map(game, game->map, game->map_attributes);
	return (1);
}

void	check_game(t_game *game)
{
	if (game->result == 1)
	{
		ft_printf("Mischief managed! - You won!\n");
		end_game(game);
	}
	if (game->result == -1)
	{
		ft_printf("Avada Kedavra! - You lost!\n");
		end_game(game);
	}
	if (game->collect / 2 > game->map_attributes->collect && !(game->panic))
		game->panic = 1;
}

int	key_hook(int key, t_game *game)
{
	int	move;

	if (key == KEY_ESC)
		end_game(game);
	if (key == KEY_UP)
		move = move_player(game, game->player_row - 1, game->player_col);
	if (key == KEY_DOWN)
		move = move_player(game, game->player_row + 1, game->player_col);
	if (key == KEY_RIGHT)
		move = move_player(game, game->player_row, game->player_col + 1);
	if (key == KEY_LEFT)
		move = move_player(game, game->player_row, game->player_col - 1);
	game->move = move;
	// move this somewhere else later?
//	if (game->move)
//		display_map(game, game->map, game->map_attributes);
	return (1);
}

int	end_game(t_game *game)
{
	// free sprites? Consider other things that need to be done!!!
	mlx_clear_window(game->id, game->window);
	mlx_destroy_window(game->id, game->window);
	free (game->id);
	free (game->map);
	exit (0);
	return (0);
}

