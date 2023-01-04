/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:52:16 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/04 14:26:57 by lvogelsa         ###   ########.fr       */
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
//////////////////
char	*ft_strenlarge(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*s3;
	int		i;
	
//	if (s1 == NULL && s2 == NULL)
//		return (NULL);
	if (s1 == NULL)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (s2 == NULL)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
		return (NULL);
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			s3[i] = s1[i];
		if (i < len_s2)
			s3[i + len_s1] = s2[i];
		i++;
	}
	s3[len_s1 + len_s2] = '\0';
	free(s1);
	free(s2);
	return (s3);
}
