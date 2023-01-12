/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:56 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/12 11:44:59 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Using the mlx library, we load all the sprites we want to display in the
//game and free them later.

void	init_sprites(t_game *game)
{
	int	size;

	size = SPRITE_SIZE;
	game->sprites.wall = mlx_xpm_file_to_image(game->id, \
	"sprites/wall.xpm", &size, &size);
	game->sprites.floor = mlx_xpm_file_to_image(game->id, \
	"sprites/floor.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->id, \
	"sprites/floo_network.xpm", &size, &size);
	game->sprites.player = mlx_xpm_file_to_image(game->id, \
	"sprites/harrypotter.xpm", &size, &size);
	game->sprites.enemy = mlx_xpm_file_to_image(game->id, \
	"sprites/voldemort.xpm", &size, &size);
	game->sprites.enemypanic = mlx_xpm_file_to_image(game->id, \
	"sprites/voldemort_panic.xpm", &size, &size);
	init_sprites_two(game, size);
}

void	init_sprites_two(t_game *game, int size)
{
	game->sprites.c_one = mlx_xpm_file_to_image(game->id, \
	"sprites/horcrux_cup.xpm", &size, &size);
	game->sprites.c_two = mlx_xpm_file_to_image(game->id, \
	"sprites/horcrux_diadem.xpm", &size, &size);
	game->sprites.c_three = mlx_xpm_file_to_image(game->id, \
	"sprites/horcrux_diary.xpm", &size, &size);
	game->sprites.c_four = mlx_xpm_file_to_image(game->id, \
	"sprites/horcrux_locket.xpm", &size, &size);
	game->sprites.c_five = mlx_xpm_file_to_image(game->id, \
	"sprites/horcrux_nagini.xpm", &size, &size);
	game->sprites.c_six = mlx_xpm_file_to_image(game->id, \
	"sprites/horcrux_ring.xpm", &size, &size);
}

void	init_fonts(t_game *game)
{
	int	size;

	size = SPRITE_SIZE;
	game->fonts.zero = mlx_xpm_file_to_image(game->id, \
	"sprites/font_zero.xpm", &size, &size);
	game->fonts.one = mlx_xpm_file_to_image(game->id, \
	"sprites/font_one.xpm", &size, &size);
	game->fonts.two = mlx_xpm_file_to_image(game->id, \
	"sprites/font_two.xpm", &size, &size);
	game->fonts.three = mlx_xpm_file_to_image(game->id, \
	"sprites/font_three.xpm", &size, &size);
	game->fonts.four = mlx_xpm_file_to_image(game->id, \
	"sprites/font_four.xpm", &size, &size);
	game->fonts.five = mlx_xpm_file_to_image(game->id, \
	"sprites/font_five.xpm", &size, &size);
	game->fonts.six = mlx_xpm_file_to_image(game->id, \
	"sprites/font_six.xpm", &size, &size);
	game->fonts.seven = mlx_xpm_file_to_image(game->id, \
	"sprites/font_seven.xpm", &size, &size);
	game->fonts.eight = mlx_xpm_file_to_image(game->id, \
	"sprites/font_eight.xpm", &size, &size);
	game->fonts.nine = mlx_xpm_file_to_image(game->id, \
	"sprites/font_nine.xpm", &size, &size);
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
