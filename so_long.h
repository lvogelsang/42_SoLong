/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:29:05 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/03 10:37:14 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

// This is a structure that stores the layout properties of the map, including
// rows, columns, location of exits, the player, enemies, and collectibles.

typedef struct s_map
{
	int	n_row;
	int	n_col;
	int	n_exit;
	int	n_player;
	int	n_enemy;
	int	n_collect;
}		t_map;

#endif
