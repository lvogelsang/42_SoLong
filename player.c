/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:29:06 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/05 15:39:34 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*init_player(char **map)
{
	t_player *player;
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				player->position_x = x;
				player->position_y = y;
			}
			y++;
		}
		x++;
	}
	player->window_position_x = player->position_x * SPRITE_SIZE;
	player->window_position_y = player->position_y * SPRITE_SIZE;
	return (player);
}

void	display_player(t_game *game)
{/*
	mlx_put_image_to_window(game->id, g->window, g->sprites.black, \
			game->player->window_position_x, game->player->window_position_y);*/
	mlx_put_image_to_window(game->id, game->window, game->sprites.player, \
			game->player->window_position_y, game->player->window_position_x);
}

