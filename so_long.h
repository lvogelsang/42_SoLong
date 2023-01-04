/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:29:05 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/04 14:22:33 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

# define MAP_CHARS	"01CEPY\n"
// This is a structure that stores the layout properties of the map, including
// rows, columns, location of exits, the player, enemies, and collectibles.

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
}		t_error;

int	error_message(char *message, char **map);
int	primitive_errors(int argc, char **argv);
void	check_map_errors(char *line, t_map *map_attributes, t_error *map_error, int first_or_last);
int	print_map_errors(t_error *map_error, t_map *map_attributes, char **map_str);

char	**check_map(int fd, t_map *map_attributes);
void	read_map(int fd, t_map *map_attributes, char **map_str, t_error *map_error);
void	get_map_attributes(char *line, t_map *attributes, t_error *map_error, int first_or_last);

t_map	init_map_attributes(void);
t_error	init_map_error(void);

int	ft_strrncmp(const char *s1, const char *s2, size_t n);
int	ft_countchar(char *str, int c);

#endif
