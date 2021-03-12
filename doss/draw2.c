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

void		drawsprite(t_game *game, float *dists, t_sprite *s)
{
/* 	height : taille du mur proportionnelement a la taille de l'ecran et la distance entre moi et l'objet
	i      : compteur entre [0, hauteur de l'objet]
	le raycasting se fait de bas en haut
	sangle : même principe que le fov sauf qu'on ne fait plus par le cos mais par le tan
	countp : -1
*/
	int		height;
	int		hcount;
	float	sangle;
	float	countp;

	height = ceil(game->ecrany *  150 / s[game->c[10]].dist);
	hcount = 0;
	while (hcount < height && height < game->ecranx * 5)
	{
		countp = -1;
		sangle = s[game->c[10]].angle + (1 - ((float)hcount / (float)height)) * atan((float)64 / s[game->c[10]].dist);
		if (sangle < 20 * 0.0174f && sangle > -20 * 0.0174f)
			countp = (game->ecranx / 2) + (sangle / (40 * 0.0174f)) * game->ecranx;
		if (dists[(int)countp] > s[game->c[10]].dist)
		{
			drawimg(game, (int)countp, hcount * 64 / height, height);
			drawimg(game, (int)countp + 1, hcount * 64 / height, height);
		}
		hcount++;
	}
}

