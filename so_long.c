/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:33:22 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/03 12:16:14 by lvogelsa         ###   ########.fr       */
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
//	map = map_errors(...);
	if (map == NULL)
		return (0);
	init_game(map, map_attributes);
	return (0);
}
