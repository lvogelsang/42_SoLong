/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:42:34 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/12 11:39:21 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a new string, which is the result of the concatenation of s1 and s2.

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*concat;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
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
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		concat = (char *)malloc(len * sizeof(char));
		if (concat == NULL)
			return (NULL);
		ft_strlcpy(concat, s1, ft_strlen(s1) + 1);
		ft_strlcpy(concat + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		free (s1);
		free (s2);
	}
	return (concat);
}
