/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:58:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/12 10:11:10 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Here is where we initiate the game, set up the basic game features, and start
//running the game using mlx functions.

//The 'hook' function of the mlx recognises events/messages, such as key
//strokes, to then modify an application, such as moving a player in a game.
//The 'loop hook' function is continuously called and in our case, has the
//purpose of redrawing our game and to execute animations that are 
//frame-dependant.
//
void	init_game(char **map, t_map *map_attributes)
{
	t_game	game;

	game.map = map;
	game.map_attributes = map_attributes;
	game.collect = map_attributes->collect;
	game.frames = 0;
	game.steps = 0;
	game.panic = 0;
	game.result = 0;
	game.id = mlx_init();
	game.window = mlx_new_window(game.id, map_attributes->col * SPRITE_SIZE, \
	map_attributes->row * SPRITE_SIZE + 64, "SO_LONG");
	init_sprites(&game);
	init_fonts(&game);
	mlx_loop_hook(game.id, update_game, &game);
	mlx_key_hook(game.window, key_hook, &game);
	mlx_hook(game.window, 17, 0, end_game, &game);
	mlx_loop(game.id);
}

//This is where we check the game status and update the game. We check whether
//the player has won, lost or if panic mode needs to be activated. Then we 
//display the map and the score on the screen.

int	update_game(t_game *game)
{
	game->frames++;
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
	display_map(game, game->map, game->map_attributes);
	display_score(game);
	return (1);
}

//This is our 'Key Hook' function. If the player presses any arrow keys, we 
//move the player in the game (if possible). I the ESC key is pressed, the 
//game ends.

int	key_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		end_game(game);
	if (key == KEY_UP)
		move_player(game, game->player_row - 1, game->player_col);
	if (key == KEY_DOWN)
		move_player(game, game->player_row + 1, game->player_col);
	if (key == KEY_RIGHT)
		move_player(game, game->player_row, game->player_col + 1);
	if (key == KEY_LEFT)
		move_player(game, game->player_row, game->player_col - 1);
	return (1);
}

//This function evaluates the pressed key - First, it checks whether the player 
//wants to move to an 'illegal' position. If the move is allowed, I check 
//whether the player is winning, losing, picking up a collectible, or moving 
//to an empty space. Based on that information, I modify the map which then 
//will be displayed in the mlx_loop_hook 'update_game'.

void	*move_player(t_game *game, int row, int col)
{
	if (game->map[row][col] == '1' || (game->map[row][col] == 'E' && \
		game->map_attributes->collect))
		return (NULL);
	else
		game->map[game->player_row][game->player_col] = '0';
	if (game->map[row][col] == 'E' && !(game->map_attributes->collect))
		game->result = 1;
	else if (game->map[row][col] == 'Y')
		game->result = -1;
	else if (game->map[row][col] == 'C' || game->map[row][col] == '0')
	{
		if (game->map[row][col] == 'C')
			game->map_attributes->collect--;
		game->map[row][col] = 'P';
		game->player_row = row;
		game->player_col = col;
	}
	game->steps++;
	return (NULL);
}

//If the game ends, we free everything that was allocated with malloc.

int	end_game(t_game *game)
{
	free_sprites(game);
	free_fonts(game);
	mlx_clear_window(game->id, game->window);
	mlx_destroy_window(game->id, game->window);
	free (game->id);
	free (game->map);
	exit (0);
	return (0);
}
