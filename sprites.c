/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:17:52 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/05 15:25:14 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprites	init_sprites(t_game *game)
{
	int	size;

	size = SPRITE_SIZE;
	game->sprites.wall = mlx_xpm_file_to_image(game->id, "sprites/walls.xpm", &size, &size);
	game->sprites.floor = mlx_xpm_file_to_image(game->id, "sprites/floor.xpm", &size, &size);
	game->sprites.collectone = mlx_xpm_file_to_image(game->id, "sprites/collect.xpm", &size, &size);
	game->sprites.collecttwo = mlx_xpm_file_to_image(game->id, "sprites/diary.xpm", &size, &size);
	game->sprites.player = mlx_xpm_file_to_image(game->id, "sprites/player.xpm", &size, &size);
	game->sprites.enemy = mlx_xpm_file_to_image(game->id, "sprites/voldemort.xpm", &size, &size);
	game->sprites.enemypanic = mlx_xpm_file_to_image(game->id, "sprites/voldemort_panic.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->id, "sprites/exit.xpm", &size, &size);
	return (game->sprites);
}
