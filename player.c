/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:38:23 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/10 16:10:14 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_game *game, int row, int col)
{
	if (game->map[row][col] == '1' || (game->map[row][col] == 'E' && game->map_attributes->collect))
		return (0);
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
	return (1);
}
