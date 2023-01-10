/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:21:19 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/10 16:08:11 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map_attributes(void)
{
	t_map map_attributes;

	map_attributes.row = 0;
	map_attributes.col = 0;
	map_attributes.exit = 0;
	map_attributes.player = 0;
	map_attributes.enemy = 0;
	map_attributes.collect = 0;
	return (map_attributes);
}

char	**check_map(int fd, t_map *map_attributes)
{
	char	*map_str;
	char	**map;
	t_error	map_error;
	
	map_str = NULL;
	map = NULL;
	map_error = init_map_error();
	read_map(fd, map_attributes, &map_str, &map_error);
	if (print_map_errors(&map_error, map_attributes, map_str) == -1)
	//	free (map_str);//Already freeing with error message?
		return (NULL);
	map = ft_split(map_str, '\n');
	free (map_str);
	if (map == NULL)
		error_message("Memory allocation problem!", NULL);
	return (map);
}

void	*read_map(int fd, t_map *map_attributes, char **map_str, t_error *map_error)
{
	char	*prev_line;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (map_attributes->row == 0)
				map_error->rectangle = -1;
			else
			{
				get_map_attributes(prev_line, map_attributes, map_error, 1);
				free (prev_line);
			}
			break ;
		}
		if (map_attributes->row > 0)
			free (prev_line);
		get_map_attributes(line, map_attributes, map_error, !(map_attributes->row));
		prev_line = ft_substr(line, 0, ft_strlen(line));
		*map_str = ft_strjoin(*map_str, line);
		if (*map_str == NULL)
		{
			map_error->memory = 1;
			return (NULL);
		}
		map_attributes->row++;
	}
	if (*map_str)
		check_map_valid_path(*map_str, map_attributes, map_error);
	return (NULL);
}

void	get_map_attributes(char *line, t_map *map_attributes, t_error *map_error, int first_or_last)
{
	if (!(map_attributes->col))
		map_attributes->col = ft_strlen(line) - 1;
	map_attributes->exit += ft_countchar(line, 'E');
	map_attributes->player += ft_countchar(line, 'P');
	map_attributes->enemy += ft_countchar(line, 'Y');
	map_attributes->collect += ft_countchar(line, 'C');
	check_map_errors(line, map_attributes, map_error, first_or_last);
}
