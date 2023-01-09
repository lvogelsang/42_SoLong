/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:58:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/09 14:15:31 by lvogelsa         ###   ########.fr       */
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
	map_attributes->row * SPRITE_SIZE + 80, "HARRY POTTER - The Game that took so long");
	game.sprites = init_sprites(&game);
	display_map(&game, map, map_attributes);
	mlx_loop(game.id);
}


