/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:22:57 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/11 12:23:12 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// First, we check for any primitive errors and then read the map and record its
// attributes. While doing that, we check whether the map is meeting the
// requirements as per the project instructions.

int	main(int argc, char **argv)
{
	int		fd;
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
