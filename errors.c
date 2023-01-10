/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:12:48 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/10 11:58:12 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_message(char *message, char *map_str)
{
	if (map_str)
		free (map_str);
	ft_printf("Error!!! %s\n", message);
	exit (0);
	return (-1);
}

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
//
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
//
void	check_map_errors(char *line, t_map *map_attributes, t_error *map_error, int first_or_last)
{
	int	i;

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
}
//Reverse x and y to make it tidier:
void	*check_map_valid_path(char *map_str, t_map *map_attributes, t_error *map_error)
{
	char 	**map;
	int	x;
	int	y;
	
	map = ft_split(map_str, '\n');
	if (map == NULL)
	{
		map_error->memory = 1;
		return (NULL);
	}
	x = 1;
	while (x < map_attributes->col - 1)
	{
		y = 1;
		while (y < map_attributes->row - 1)
		{
			if (map[y][x + 1] == 'P' || map[y][x - 1] == 'P' \
				|| map[y + 1][x] == 'P' || map[y - 1][x] == 'P')
			{
				if (map[y][x] == '0' || map[y][x] == 'C')
				{
					map[y][x] = 'P';
					x = 0;
					break ;
				}
				if (map[y][x] == 'E')
				{
					map[y][x] = '1';
					x = 0;
					break ;
				}
			}
			y++;
		}
		x++;
	}
	check_map_valid_path_two(map, map_error);
	free (map);
	return (NULL);
}

void	check_map_valid_path_two(char **map, t_error *map_error)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				map_error->path = 1;
			y++;
		}
		x++;
	}
}

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
		return (error_message("The map doesn't contain a valid path!", map_str));
	if (map_error->memory)
		return (error_message("Memory allocation problems!", map_str));
	return (0);
}
