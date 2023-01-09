/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:55:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/09 12:36:25 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define MAP_CHARS	"01CEPY\n"

typedef struct	s_map
{
	int	row;
	int	col;
	int	exit;
	int	player;
	int	enemy;
	int	collect;
}		t_map;

typedef struct	s_error
{
	int	rectangle;
	int	closed;
	int	chars;
	int	path;
	int	memory;
}		t_error;

// SO_LONG.C

// ERRORS.C

int	error_message(char *message, char *map_str);
int	primitive_errors(int argc, char **argv);
t_error	init_map_error(void);
void	check_map_errors(char *line, t_map *map_attributes, t_error *map_error, int first_or_last);
void	*check_map_valid_path(char *map_str, t_map *map_attributes, t_error *map_error);
void	check_map_valid_path_two(char **map, t_error *map_error);
int	print_map_errors(t_error *map_error, t_map *map_attributes, char *map_str);

// MAP.C

t_map init_map_attributes(void);
char	**check_map(int fd, t_map *map_attributes);
void	*read_map(int fd, t_map *map_attributes, char **map_str, t_error *map_error);
void	get_map_attributes(char *line, t_map *map_attributes, t_error *map_error, int first_or_last);

// UTILS.C

int	ft_strrncmp(const char *s1, const char *s2, size_t n);
int	ft_countchar(char *str, int c);

#endif
