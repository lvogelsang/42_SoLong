/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:30:53 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/10 12:19:41 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_score(t_game *game)
{
	int	i;
	int	score;
	int	digit;

	i = 0;
	score = game->steps;
	while (i < 4)
	{
		digit = score % 10;
		score = score / 10;
		display_font(game, digit, i);
		i++;
	}
}

void	display_font(t_game *game, int digit, int i)
{
	void	*font;

	font = NULL;
	if (digit == 0)
		font = game->fonts.zero;
	if (digit == 1)
		font = game->fonts.one;
	if (digit == 2)
		font = game->fonts.two;
	if (digit == 3)
		font = game->fonts.three;
	if (digit == 4)
		font = game->fonts.four;
	if (digit == 5)
		font = game->fonts.five;
	if (digit == 6)
		font = game->fonts.six;
	if (digit == 7)
		font = game->fonts.seven;
	if (digit == 8)
		font = game->fonts.eight;
	if (digit == 9)
		font = game->fonts.nine;
	mlx_put_image_to_window(game->id, game->window, font, (3 - i) * SPRITE_SIZE, game->map_attributes->row * SPRITE_SIZE);
}
