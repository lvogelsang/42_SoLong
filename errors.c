/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:12:48 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/12 11:31:18 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Error message function.

int	error_message(char *message, char *map_str)
{
	if (map_str)
		free (map_str);
	ft_printf("Error!!! %s\n", message);
	exit (0);
	return (-1);
}

// This function checks for any primitive errors, such as an invalid file type.

int	primitive_errors(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (error_message("Invalid number of arguments!", NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_message("File not found!", NULL));
	if (ft_strrncmp(argv[1], ".ber", 4))
		return (error_message("Invalid file type!", NULL));
	return (fd);
}

// Here we initiate a struct that stores every potential error of the map.

t_error	init_map_error(void)
{
	t_error	map_error;

	map_error.rectangle = 0;
	map_error.closed = 0;
	map_error.chars = 0;
	map_error.path = 0;
	map_error.memory = 0;
	return (map_error);
}

// This function tests the map for errors, including whether it is rectangular, 
// surrounded by walls, or if it contains any invalid characters.

void	check_map_errors(char *line, t_map *map_attributes, \
t_error *map_error, int first_or_last)
{
	int	i;

	if (map_attributes->col && ((map_attributes->col != \
		(int)ft_strlen(line) - 1 && ft_strchr(line, '\n')) || \
		(map_attributes->col != (int)ft_strlen(line) \
		&& !(ft_strchr(line, '\n')))))
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
}

//This function checks whether a valid path exists in the map, i.e., the
//player must be able to reach every collectible and the exit. If a player 
//can reach a specific spot on the map, I fill it with a 'P'. If there are 
//still 'C's or an 'E' left at the end, then the map is invalid.

void	*check_map_valid_path(char *map_str, t_map *map_attributes, \
t_error *map_error)
{
	char	**map;
	int		col;
	int		row;

	map = ft_split(map_str, '\n');
	if (map == NULL)
	{
		map_error->memory = 1;
		return (NULL);
	}
	col = 1;
	while (col < map_attributes->col - 1)
		col = check_map_valid_path_two(map, map_attributes, col, 1);
	row = 0;
	while (row < map_attributes->row)
	{
		map_error->path += ft_countchar(&map[row][0], 'C');
		map_error->path += ft_countchar(&map[row][0], 'E');
		row++;
	}
	////
	int	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	////
	free (map);
	return (NULL);
}

int	check_map_valid_path_two(char **map, t_map *map_attributes, \
int col, int row)
{
	while (row < map_attributes->row - 1)
	{
		if (map[row][col + 1] == 'P' || map[row][col - 1] == 'P' \
			|| map[row + 1][col] == 'P' || map[row - 1][col] == 'P')
		{
			if (map[row][col] == '0' || map[row][col] == 'C')
			{
				map[row][col] = 'P';
				return (0);
			}
			if (map[row][col] == 'E')
			{
				map[row][col] = '1';
				return (0);
			}
		}
		row++;
	}
	col++;
	return (col);
}

// This function goes through the map attributes and prints a specific error 
// message to the terminal if an error has occured..

int	print_map_errors(t_error *map_error, t_map *map_attributes, char *map_str)
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
	if (map_error->path)
		return (error_message("There is no valid path!", map_str));
	if (map_error->memory)
		return (error_message("Memory allocation problems!", map_str));
	return (0);
}
