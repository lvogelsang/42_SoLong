/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:41:01 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/03 12:58:45 by lvogelsa         ###   ########.fr       */
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
		free(map);
	ft_printf("Error!!! %s\n", message);
	exit(0);
	return (-1);
}
