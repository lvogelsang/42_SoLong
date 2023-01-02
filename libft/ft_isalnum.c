/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:10:17 by lvogelsa          #+#    #+#             */
/*   Updated: 2022/09/26 10:19:30 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	x;

	if (ft_isalpha(c) == 1
		|| ft_isdigit(c) == 1)
	{
		x = 1;
	}
	else
	{
		x = 0;
	}
	return (x);
}
