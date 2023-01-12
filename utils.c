/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:18:32 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/12 11:57:06 by lvogelsa         ###   ########.fr       */
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

//A modified version of strjoin.

char	*ft_strjoin_sl(char *s1, char *s2)
{
	char	*concat;

	if (s1 == NULL)
	{
		concat = ft_substr(s2, 0, ft_strlen(s2));
		free (s2);
	}
	else if (s2 == NULL)
	{
		concat = ft_substr(s1, 0, ft_strlen(s1));
		free (s1);
	}
	else
	{
		concat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) \
				* sizeof(char));
		if (concat == NULL)
			return (NULL);
		ft_strlcpy(concat, s1, ft_strlen(s1) + 1);
		ft_strlcpy(concat + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		free (s1);
		free (s2);
	}
	return (concat);
}

//A short function to help freeing the map.

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}
