/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:18:32 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/11 13:57:10 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//A modification of the strncmp function of the libft library - here it 
//compares the strings from the back.

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while ((s1[i - 1] || s2[j - 1]) && n > 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			i--;
			j--;
			n--;
		}
		else
			return (s1[i - 1] - s2[j - 1]);
	}
	return (0);
}

//This function counts how many times a character appears in a line.

int	ft_countchar(char *str, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
