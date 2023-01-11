/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:04:26 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/11 13:58:39 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//With this function, we loop through the map, evaluate the character, and 
//display it to the window.

void	display_map(t_game *game, char **map, t_map *map_attributes)
{
	int			row;
	int			col;
	static int	x;

	if (game->frames == 1 || x == 9)
		x = 0;
	row = 0;
	while (row < map_attributes->row)
	{
		col = 0;
		while (col < map_attributes->col)
		{
			display_map_two(game, map, row, col);
			if (map[row][col] == 'Y')
				display_enemy(game, x, row, col);
			col++;
		}
		row++;
	}
	x++;
}

void	display_map_two(t_game *game, char **map, int row, int col)
{
	if (map[row][col] == '0' || map[row][col] == 'E' || map[row][col] == 'C' \
		|| map[row][col] == 'P' || map[row][col] == 'Y')
		mlx_put_image_to_window(game->id, game->window, game->sprites.floor, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (map[row][col] == '1')
		mlx_put_image_to_window(game->id, game->window, game->sprites.wall, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (map[row][col] == 'E')
		mlx_put_image_to_window(game->id, game->window, game->sprites.exit, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (map[row][col] == 'P')
		display_player(game, row, col);
	if (map[row][col] == 'C')
		display_collectible(game, row, col);
}

//This function displays the player to the window and saves the position of
//the player to the game struct.

void	display_player(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->id, game->window, game->sprites.player, \
	col * SPRITE_SIZE, row * SPRITE_SIZE);
	game->player_row = row;
	game->player_col = col;
}

//This function displays the enemy to the window and takes into consideration
//if the enemy is in panic mode.

void	display_enemy(t_game *game, int x, int row, int col)
{
	if (!(game->panic) || (game->panic && x < 5))
		mlx_put_image_to_window(game->id, game->window, game->sprites.enemy, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (game->panic && x > 4)
		mlx_put_image_to_window(game->id, game->window, \
		game->sprites.enemypanic, col * SPRITE_SIZE, row * SPRITE_SIZE);
}

//This function displays the collectibles to the window. As we have six
//collectibles, we choose it based on its position.

void	display_collectible(t_game *game, int row, int col)
{
	if (row % 3 == 0 && col % 2 == 0)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_one, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 0 && col % 2 == 1)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_two, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 1 && col % 2 == 0)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_three, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 1 && col % 2 == 1)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_four, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 2 && col % 2 == 0)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_five, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 2 && col % 2 == 1)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_six, \
		col * SPRITE_SIZE, row * SPRITE_SIZE);
}

//These functions display the score to the window.

void	display_score(t_game *game)
{
	int	i;
	int	score;
	int	digit;

	i = 0;
	score = game->steps;
	while (i < 4)
	{
		digit = score % 10;
		score = score / 10;
		display_score_two(game, digit, i);
		i++;
	}
}

void	display_score_two(t_game *game, int digit, int i)
{
	void	*font;

	font = NULL;
	if (digit == 0)
		font = game->fonts.zero;
	if (digit == 1)
		font = game->fonts.one;
	if (digit == 2)
		font = game->fonts.two;
	if (digit == 3)
		font = game->fonts.three;
	if (digit == 4)
		font = game->fonts.four;
	if (digit == 5)
		font = game->fonts.five;
	if (digit == 6)
		font = game->fonts.six;
	if (digit == 7)
		font = game->fonts.seven;
	if (digit == 8)
		font = game->fonts.eight;
	if (digit == 9)
		font = game->fonts.nine;
	mlx_put_image_to_window(game->id, game->window, \
	font, (3 - i) * SPRITE_SIZE, game->map_attributes->row * SPRITE_SIZE);
}
