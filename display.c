/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:29 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/05 15:48:01 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->id, game->window, game->sprites.wall, \
			y * SPRITE_SIZE, x * SPRITE_SIZE);
	if (game->map[x][y] == 'E')
		mlx_put_image_to_window(game->id, game->window, game->sprites.exit, \
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->id, game->window, game->sprites.collectone, \
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	//-------
/*	if (game->map[x][y] == '0')
		mlx_put_image_to_window(game->id, game->window, game->sprites.player, \
		x * SPRITE_SIZE, y * SPRITE_SIZE);
*/}
