/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:56 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/09 14:16:28 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprites	init_sprites(t_game *game)
{
	int	size;

	size = SPRITE_SIZE;
	game->sprites.wall = mlx_xpm_file_to_image(game->id, "sprites/wall.xpm", &size, &size);
	game->sprites.floor = mlx_xpm_file_to_image(game->id, "sprites/floor.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->id, "sprites/floo_network.xpm", &size, &size);
	game->sprites.player = mlx_xpm_file_to_image(game->id, "sprites/harrypotter.xpm", &size, &size);
	game->sprites.enemy = mlx_xpm_file_to_image(game->id, "sprites/voldemort.xpm", &size, &size);
	game->sprites.enemypanic = mlx_xpm_file_to_image(game->id, "sprites/voldemort_panic.xpm", &size, &size);
	game->sprites.c_one = mlx_xpm_file_to_image(game->id, "sprites/horcrux_cup.xpm", &size, &size);
	game->sprites.c_two = mlx_xpm_file_to_image(game->id, "sprites/horcrux_diadem.xpm", &size, &size);
	game->sprites.c_three = mlx_xpm_file_to_image(game->id, "sprites/horcrux_diary.xpm", &size, &size);
	game->sprites.c_four = mlx_xpm_file_to_image(game->id, "sprites/horcrux_locket.xpm", &size, &size);
	game->sprites.c_five = mlx_xpm_file_to_image(game->id, "sprites/horcrux_nagini.xpm", &size, &size);
	game->sprites.c_six = mlx_xpm_file_to_image(game->id, "sprites/horcrux_ring.xpm", &size, &size);
	return (game->sprites);
}

void	display_map(t_game *game, char **map, t_map *map_attributes)
{
	int	row;
	int	col;

	row = 0;
	while (row < map_attributes->row)
	{
		col = 0;
		while (col < map_attributes->col)
		{
			if (map[row][col] == '0' || map[row][col] == 'E' || map[row][col] == 'C' \
				|| map[row][col] == 'P' || map[row][col] == 'Y')
				mlx_put_image_to_window(game->id, game->window, game->sprites.floor, col * SPRITE_SIZE, row * SPRITE_SIZE);
			if (map[row][col] == '1')
				mlx_put_image_to_window(game->id, game->window, game->sprites.wall, col * SPRITE_SIZE, row * SPRITE_SIZE);
			if (map[row][col] == 'E')
				mlx_put_image_to_window(game->id, game->window, game->sprites.exit, col * SPRITE_SIZE, row * SPRITE_SIZE);
			if (map[row][col] == 'P')
				display_player(game, row, col);
			//Incorporate panic mode here?
			if (map[row][col] == 'Y')
				mlx_put_image_to_window(game->id, game->window, game->sprites.enemy, col * SPRITE_SIZE, row * SPRITE_SIZE);
			if (map[row][col] == 'C')
				display_collectible(game, row, col);
			col++;
		}
		row++;
	}
}

void	display_player(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->id, game->window, game->sprites.player, col * SPRITE_SIZE, row * SPRITE_SIZE);
	game->player_row = row;
	game->player_col = col;
}

void	display_collectible(t_game *game, int row, int col)
{
	if (row % 3 == 0 && col % 2 == 0)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_one, col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 0 && col % 2 == 1)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_two, col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 1 && col % 2 == 0)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_three, col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 1 && col % 2 == 1)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_four, col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 2 && col % 2 == 0)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_five, col * SPRITE_SIZE, row * SPRITE_SIZE);
	if (row % 3 == 2 && col % 2 == 1)
		mlx_put_image_to_window(game->id, game->window, game->sprites.c_six, col * SPRITE_SIZE, row * SPRITE_SIZE);
}

