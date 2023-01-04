/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:03:44 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/04 14:15:22 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map_attributes(void)
{
	t_map	map_attributes;

	map_attributes.row = 0;
	map_attributes.col = 0;
	map_attributes.exit = 0;
	map_attributes.player = 0;
	map_attributes.enemy = 0;
	map_attributes.collect = 0;
	return (map_attributes);
}

t_error	init_map_error(void)
{
	t_error	map_error;

	map_error.rectangle = 0;
	map_error.closed = 0;
	map_error.chars = 0;
	map_error.path = 0;
	return (map_error);
}
