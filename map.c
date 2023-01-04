/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:07:08 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/04 14:23:18 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_map(int fd, t_map *map_attributes)
{
	char	*map_str;
	char	**map;
	int	err;
	t_error	map_error;

	map_str = NULL;
	map_error = init_map_error();
	read_map(fd, map_attributes, &map_str, &map_error);
	err = print_map_errors(&map_error, map_attributes, &map_str);
	if (err == -1)
	{
		free (map_str);
		return (NULL);
	}
	map = ft_split(map_str, '\n');
	free (map_str);
	if (map == NULL)
		error_message("Memory allocation problem!", NULL);
	return (map);
}

//
char	*ft_strenlarge(char *s1, char *s2);
//

void	read_map(int fd, t_map *map_attributes, char **map_str, t_error *map_error)
{
	char	*prev_line;
	char	*line;
	
	prev_line = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (map_attributes->row == 0)
				map_error->rectangle = -1;
			else
				get_map_attributes(prev_line, map_attributes, map_error, 1);
			free (prev_line);
		//	free (line);
			break ;
		}
		free (prev_line);
		get_map_attributes(line, map_attributes, map_error, !(map_attributes->row));
//		ft_printf("C: %d E: %d P: %d Y: %d\n", map_attributes.collect, map_attributes.exit, map_attributes.player, map_attributes.enemy);
		prev_line = ft_substr(line, 0, ft_strlen(line));
//		ft_printf("seg1");
		*map_str = ft_strenlarge(*map_str, line);
//		ft_printf("seg2");
	//	free (line);
	}
}

void	get_map_attributes(char *line, t_map *map_attributes, t_error *map_error, int first_or_last)
{
	map_attributes->row++;
	if (!(map_attributes->col))
		map_attributes->col = ft_strlen(line) - 1;
//	ft_printf("1C: %d E: %d P: %d Y: %d\n", map_attributes.collect, map_attributes.exit, map_attributes.player, map_attributes.enemy);
//	ft_printf("C: %d\nE: %d\nP: %d\nY: %d\n", ft_countchar(line, 'C'), ft_countchar(line, 'E'), ft_countchar(line, 'P'), ft_countchar(line, 'Y'));
	map_attributes->collect += ft_countchar(line, 'C');
	map_attributes->exit += ft_countchar(line, 'E');
	map_attributes->player += ft_countchar(line, 'P');
	map_attributes->enemy += ft_countchar(line, 'Y');
//	ft_printf("2C: %d E: %d P: %d Y: %d\n", map_attributes.collect, map_attributes.exit, map_attributes.player, map_attributes.enemy);
	check_map_errors(line, map_attributes, map_error, first_or_last);
//	ft_printf("ERR: %d\n", map_error.closed);
}

