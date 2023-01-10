/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:56 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/10 16:02:48 by lvogelsa         ###   ########.fr       */
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

t_font	init_fonts(t_game *game)
{
	int	size;

	size = SPRITE_SIZE;
	game->fonts.zero = mlx_xpm_file_to_image(game->id, "sprites/font_zero.xpm", &size, &size);
	game->fonts.one = mlx_xpm_file_to_image(game->id, "sprites/font_one.xpm", &size, &size);
	game->fonts.two = mlx_xpm_file_to_image(game->id, "sprites/font_two.xpm", &size, &size);
	game->fonts.three = mlx_xpm_file_to_image(game->id, "sprites/font_three.xpm", &size, &size);
	game->fonts.four = mlx_xpm_file_to_image(game->id, "sprites/font_four.xpm", &size, &size);
	game->fonts.five = mlx_xpm_file_to_image(game->id, "sprites/font_five.xpm", &size, &size);
	game->fonts.six = mlx_xpm_file_to_image(game->id, "sprites/font_six.xpm", &size, &size);
	game->fonts.seven = mlx_xpm_file_to_image(game->id, "sprites/font_seven.xpm", &size, &size);
	game->fonts.eight = mlx_xpm_file_to_image(game->id, "sprites/font_eight.xpm", &size, &size);
	game->fonts.nine = mlx_xpm_file_to_image(game->id, "sprites/font_nine.xpm", &size, &size);
	return (game->fonts);
}

void	display_map(t_game *game, char **map, t_map *map_attributes)
{
	int	row;
	int	col;
	static int	x;
	
	if (game->frames == 1 || x == 9)
		x = 0;
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
			if (map[row][col] == 'Y' && ((!(game->panic) || (game->panic && x < 5))))
				mlx_put_image_to_window(game->id, game->window, game->sprites.enemy, col * SPRITE_SIZE, row * SPRITE_SIZE);
			if (map[row][col] == 'Y' && game->panic && x > 4)
				mlx_put_image_to_window(game->id, game->window, game->sprites.enemypanic, col * SPRITE_SIZE, row * SPRITE_SIZE);
			if (map[row][col] == 'C')
				display_collectible(game, row, col);
			col++;
		}
		row++;
	}
	x++;
}	
// Incorporate this into the rest of the code:
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

void	free_sprites(t_game *game)
{
	mlx_destroy_image(game->id, game->sprites.wall);
	mlx_destroy_image(game->id, game->sprites.floor);
	mlx_destroy_image(game->id, game->sprites.exit);
	mlx_destroy_image(game->id, game->sprites.player);
	mlx_destroy_image(game->id, game->sprites.enemy);
	mlx_destroy_image(game->id, game->sprites.enemypanic);
	mlx_destroy_image(game->id, game->sprites.c_one);
	mlx_destroy_image(game->id, game->sprites.c_two);
	mlx_destroy_image(game->id, game->sprites.c_three);
	mlx_destroy_image(game->id, game->sprites.c_four);
	mlx_destroy_image(game->id, game->sprites.c_five);
	mlx_destroy_image(game->id, game->sprites.c_six);
}

void	free_fonts(t_game *game)
{
	mlx_destroy_image(game->id, game->fonts.zero);
	mlx_destroy_image(game->id, game->fonts.one);
	mlx_destroy_image(game->id, game->fonts.two);
	mlx_destroy_image(game->id, game->fonts.three);
	mlx_destroy_image(game->id, game->fonts.four);
	mlx_destroy_image(game->id, game->fonts.five);
	mlx_destroy_image(game->id, game->fonts.six);
	mlx_destroy_image(game->id, game->fonts.seven);
	mlx_destroy_image(game->id, game->fonts.eight);
	mlx_destroy_image(game->id, game->fonts.nine);
}
