/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:55:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/12 11:57:02 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define MAP_CHARS	"01CEPY\n"
# define SPRITE_SIZE	64

# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124

typedef struct s_map
{
	int	row;
	int	col;
	int	exit;
	int	player;
	int	enemy;
	int	collect;
}		t_map;

typedef struct s_error
{
	int	rectangle;
	int	closed;
	int	chars;
	int	path;
	int	memory;
}		t_error;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*player;
	void	*enemy;
	void	*enemypanic;
	void	*c_one;
	void	*c_two;
	void	*c_three;
	void	*c_four;
	void	*c_five;
	void	*c_six;
}		t_sprites;

typedef struct s_font
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}		t_font;

typedef struct s_game
{
	void		*id;
	void		*window;
	char		**map;
	int			frames;
	int			collect;
	int			player_row;
	int			player_col;
	int			panic;
	int			result;
	int			steps;
	t_map		*map_attributes;
	t_sprites	sprites;
	t_font		fonts;
}		t_game;

// SO_LONG.C

void	init_game(char **map, t_map *map_attributes);
int		update_game(t_game *game);
int		key_hook(int key, t_game *game);
void	*move_player(t_game *game, int row, int col);
int		end_game(t_game *game);

// ERRORS.C

int		error_message(char *message, char *map_str);
int		primitive_errors(int argc, char **argv);
t_error	init_map_error(void);
void	check_map_errors(char *line, t_map *map_attributes, \
t_error *map_error, int first_or_last);
void	*check_map_valid_path(char *map_str, t_map *map_attributes, \
t_error *map_error);
int		check_map_valid_path_two(char **map, \
t_map *map_attributes, int col, int row);
int		print_map_errors(t_error *map_error, \
t_map *map_attributes, char *map_str);

// MAP.C

t_map	init_map_attributes(void);
char	**check_map(int fd, t_map *map_attributes);
void	read_map(int fd, t_map *map_attributes, char **map_str, \
t_error *map_error);
void	read_map_two(t_map *map_attributes, t_error *map_error, \
char *prev_line);
void	get_map_attributes(char *line, t_map *map_attributes, \
t_error *map_error, int first_or_last);

// SPRITES.C

void	init_sprites(t_game *game);
void	init_sprites_two(t_game *game, int size);
void	init_fonts(t_game *game);
void	free_sprites(t_game *game);
void	free_fonts(t_game *game);

// DISPLAY.C

void	display_map(t_game *game, char **map, t_map *map_attributes);
void	display_map_two(t_game *game, char **map, int row, int col);
void	display_player(t_game *game, int row, int col);
void	display_enemy(t_game *game, int x, int row, int col);
void	display_collectible(t_game *game, int row, int col);
void	display_score(t_game *game);
void	display_score_two(t_game *game, int digit, int i);

// UTILS.C

int		ft_strrncmp(const char *s1, const char *s2, size_t n);
int		ft_countchar(char *str, int c);
char	*ft_strjoin_sl(char *s1, char *s2);
void	ft_free_map(char **map);

#endif
