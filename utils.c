/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:52:16 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/03 13:01:32 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
