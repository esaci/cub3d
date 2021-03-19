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

void		drawimg(t_game *game, int colecr, int wcount, int height)
{
	int		i;
	int		larg;
	int		y;

	i = 0;
	while (i < height)
	{
		larg = 64 * i / height;
		y = game->ecranx * (i + ((game->ecrany - height) / 2)) * 4;
		if (!(y > game->ecranx * game->ecrany * 4 || y < -colecr * 4))
		{
			if (ft_strncmp(game->img.data[2], game->img.data[2]
				+ wcount * 4 + larg * 64 * 4, 3) != 0)
				ft_memcpy(game->img.data[7] + y + colecr * 4,
					&(game->img.data[2][wcount * 4 + larg * 64 * 4]), 4);
		}
		i++;
	}
}

void		drawsprite(t_game *game, float *dists, t_sprite *s)
{
	int		height;
	int		hcount;
	float	sangle;
	float	colecr;

	height = ceil(game->ecranx * 150 / s[game->c[10]].dist);
	hcount = 0;
	while (hcount < height && height < game->ecranx * 5)
	{
		colecr = -1;
		sangle = s[game->c[10]].angle + (1 - ((float)hcount /
			(float)height)) * atan((float)64 / s[game->c[10]].dist);
		if (sangle < 20 * 0.0174f && sangle > -20 * 0.0174f)
			colecr = (game->ecranx / 2) +
				(sangle / (40 * 0.0174f)) * game->ecranx;
		if (dists[(int)colecr] > s[game->c[10]].dist)
		{
			drawimg(game, (int)colecr, ((float)hcount / height) * 64, height);
			drawimg(game, (int)colecr + 1, ((float)hcount /
				height) * 64, height);
		}
		hcount++;
	}
}
