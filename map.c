/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:07:08 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/03 13:43:32 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**game_map(int fd, t_map map_attributes)
{
	char	*map_str;
	char	**map;
	t_error	map_error;

	map_str = NULL;
	map_error = init_map_error();
	read_map(fd, map_attributes, map_str, map_error);
}

void	read_map(int fd, t_map map_attributes, char *map_str, t_error map_error)
{
	char	*last_line;
	char	*line;
	
	last_line = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (map_attributes->row == 0)
				map_error.rectangle = -1;
			else
				check_map(prev_line, map_attributes, map_error, 1);
			free (last_line)
		//	free (line);
			break ;
		}
		free (last_line);
		check_map(line, map_attributes, map_error, !(map_attributes->row));
		last_line = ft_substr(line, 0, ft_strlen(line));
		map_str = ft_strjoin(map_str, line);
	}
}

void	check_map(char *line, t_map map_attributes, t_error map_error, int first_or_last)
{

