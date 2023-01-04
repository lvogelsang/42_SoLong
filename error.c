/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:41:01 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/04 14:30:07 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	primitive_errors(int argc, char **argv)
{
	int	fd;
	int	error;

	if (argc != 2)
		return (error_message("Invalid number of arguments!", NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_message("File not found!", NULL));
	if (ft_strrncmp(argv[1], ".ber", 4))
		return (error_message("Invalid file type!", NULL));
	return (fd);
}
	
int	error_message(char *message, char **map)
{
	if (map)
		free(*map);
	ft_printf("Error!!! %s\n", message);
	exit(0);
	return (-1);
}

void	check_map_errors(char *line, t_map *map_attributes, t_error *map_error, int first_or_last)
{
	int	i;
	
//	ft_printf("3C: %d E: %d P: %d Y: %d\n", map_attributes.collect, map_attributes.exit, map_attributes.player, map_attributes.enemy);
	//
//	map_error.closed = 5;
	//
	if (map_attributes->col && ((map_attributes->col != ft_strlen(line) - 1 && \
		ft_strchr(line, '\n')) || (map_attributes->col != ft_strlen(line) && \
		!(ft_strchr(line, '\n')))))
		map_error->rectangle = 1;
	if (line[0] != '1' || line[map_attributes->col - 1] != '1' || \
		(first_or_last && ft_countchar(line, '1') != map_attributes->col))
		map_error->closed = 1;
	i = 0;
	while (line && line[i])
	{
		if (!(ft_strchr(MAP_CHARS, line[i])))
			map_error->chars = 1;
		i++;
	}
	//-----------------
	// Check if there is a valid path!!!
	//----------------
}

int	print_map_errors(t_error *map_error, t_map *map_attributes, char **map_str)
{
	if (map_error->rectangle == -1)
		return (error_message("The map is empty!", map_str));
	if (map_error->rectangle == 1)
		return (error_message("The map must be rectangular!", map_str));
	if (map_error->closed)
		return (error_message("The map must be surrounded by walls!", map_str));
	if (map_error->chars)
		return (error_message("The map contains invalid char(s)!", map_str));
	if (map_attributes->collect < 1)
		return (error_message("Invalid number of collectibles!", map_str));
	if (map_attributes->exit != 1)
		return (error_message("Invalid number of exits!", map_str));
	if (map_attributes->player != 1)
		return (error_message("Invalid number of players!", map_str));
	return (0);
}
