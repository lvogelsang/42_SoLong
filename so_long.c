/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:33:22 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/05 15:58:34 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int	fd;
	t_map	map_attributes;

	fd = primitive_errors(argc, argv);
	if (fd == -1)
		return (0); 
	map_attributes = init_map_attributes();
	map = check_map(fd, &map_attributes);
	if (map == NULL)
		return (0);
	init_game(map, map_attributes);
	return (0);
}

void	init_game(char **map, t_map map_attributes)
{
	t_game	game;

	game.id = mlx_init();
	game.window = mlx_new_window(game.id, map_attributes.col * SPRITE_SIZE, map_attributes.row * SPRITE_SIZE + 80, "HARRY POTTER");
//	imlx_loop(game.id);
	start_game(&game, map, &map_attributes);
}

void	start_game(t_game *game, char **map, t_map *map_attributes)
{
	game->frames = 1;
	game->sprites = init_sprites(game);
	game->map_attributes = map_attributes;
	game->collect = map_attributes->collect;
	game->map = map;
	game->panic = 0;
	game->rate = GAME_RATE;
	game->game_over = 0;
	game->player = init_player(map);
	mlx_loop_hook(game->id, update_game, (void *)game);
	mlx_loop(game->id);
}
//---
void	display_player(t_game *game);
//----
int	update_game(t_game *game)
{
	int	x;
	int	y;
	
	game->frames++;
//	check_game_status(game);
//	display_enemy(game);
//	display_score(game);
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			display_map(game, x, y);
			y++;
		}
		x++;
	}
//	display_player(game);
	return (0);
}

void	check_game_status(t_game *game)
{
	if ((!(game->map_attributes->collect) && !(game->map_attributes->player)) || (game->game_over))
		end_game(game);
	if (game->collect / 3 + 1 >= g->map_attributes->collect && game->map_attributes->enemy)
	{
		if (game->panic == 0)
			game->rate -= game->rate / 3;
		game->panic = 1;
	}
	if (!(game->frames % 2) || !(games->frames % 3) || game->panic)
		redraw_enemy(game);
	if (!(game->game_over))
	{
		redraw_player(game);
		update_enemy(game);
	}
}

int	end_game(t_game *g)
{
//	free_sprites(g);
//	ft_free_playerlist(g);
//	ft_free_matrix(&g->map);
//	ft_free_matrix(&g->map_bak);
	mlx_clear_window(g->id, g->w_id);
	mlx_destroy_window(g->id, g->w_id);
	printf("%sGame Finished!\nTotal Moves:\n");
	exit(0);
	return (0);
}

	
	



