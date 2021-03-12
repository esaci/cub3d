/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:10:00 by esaci             #+#    #+#             */
/*   Updated: 2020/12/27 22:10:05 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void		drawimg(t_game *game, int index, int n, int height)
{
	int		i;
	int		ri;
	int		y;

	i = 0;
	while (i < height)
	{
		ri = i * 64 / height;
		y = game->ecranx * 4 * (i + game->ecrany / 2 - (height / 2));
		if (!(y > game->ecranx * game->ecrany * 4 || y < -index * 4))
		{
			if (ft_strncmp(game->img.data[7],
					game->img.data[2] + n * 4 + ri * 64 * 4, 4) != 0)
			{
				ft_memcpy(game->img.data[7] + index * 4 + y,
						&(game->img.data[2][n * 4 + ri * 64 * 4]), 4);
			}
		}
		i++;
	}
}

void		drawsprite(t_game *game, float *dists, t_sprite *s, int count)
{
	int		width;
	int		i;
	float	rt;
	float	index;

	width = ceil(150 * game->ecrany / s[count].dist);
	i = 0;
	while (i < width && width < game->ecranx * 3 && (index = -1) + 2)
	{
		rt = s[count].angle + atan(64 / (2 * s[count].dist)) -
			i * 2 * atan(64 / (2 * s[count].dist)) / (float)width;
		if (rt < 40 * 0.0174f / 2 && rt > -40 * 0.0174f / 2)
			index = (game->ecranx / 2) + (rt / (40 * 0.0174f)) * game->ecranx;
		if (dists[(int)index] > s[count].dist)
		{
			drawimg(game, (int)index, i * 64 / width, width);
			drawimg(game, (int)index + 1, i * 64 / width, width);
		}
		i++;
	}
}

