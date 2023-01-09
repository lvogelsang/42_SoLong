/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:58:59 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/09 10:36:35 by lvogelsa         ###   ########.fr       */
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
//	init_game(map, map_attributes);
	return (0);
}
