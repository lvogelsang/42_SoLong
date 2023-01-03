/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:29:05 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/03 13:32:38 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

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
	int	chars;
	int	player;
	int	enemy;
	int	collect;
	int	exit;
	int	closed;
	int	valid;
}		t_error;

int	primitive_errors(int argc, char **argv);
int	error_message(char *message, char **map);

t_map	init_map_attributes(void);
t_error	init_map_error(void);

int	ft_strrncmp(const char *s1, const char *s2, size_t n);
#endif
