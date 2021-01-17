/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:16:46 by esaci             #+#    #+#             */
/*   Updated: 2021/01/13 14:16:48 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"



void			swapper(t_pix *pix1, t_pix *pix2)
{
	t_pix temp;

	temp.x = pix1->x;
	temp.y = pix1->y;
	temp.angle = pix1->angle;
	temp.dist = pix1->dist;
	temp.carac = pix1->carac;
	pix1->y = pix2->y;
	pix1->x = pix2->x;
	pix1->dist = pix2->dist;
	pix1->angle = pix2->angle;
	pix1->carac = pix2->carac;
	pix2->dist = temp.dist;
	pix2->x = temp.x;
	pix2->y = temp.y;
	pix2->angle = temp.angle;
	pix2->carac = temp.carac;
}

void			pixmodif(t_game *game, t_pix *pix)
{
	game->c[5] = 1;
	game->c[6] = 0;
	while (game->c[5])
	{
		game->c[5] = 0;
		game->c[6] = 0;
		while (pix[game->c[6] + 1].dist != -1)
		{
			if (pix[game->c[6] + 1].dist > pix[game->c[6]].dist)
			{
				swapper((pix + game->c[6] + 1), (pix + game->c[6]));
				game->c[5] = 1;
				game->c[6] = 0;
			}
			game->c[6]++;
		}
	}
}

void			init_sprite(t_game *game, t_pix *pix, int ligne, int col)
{
	pix->x = col * 64 + 64 / 2;
	pix->y = ligne * 64 + 64 / 2;
	pix->dist = ft_dist((float)(game->posy - pix->y), (float)(game->posx - pix->x));
	if (pix->dist == 0)
		pix->angle = 0;
	else if (pix->x >= game->posx)
		pix->angle = asin((game->posy - pix->y) / pix->dist);
	else
		pix->angle = -asin((game->posy - pix->y) / pix->dist) + M_PI;
	game->c[4] = pix->dist * (cos(pix->angle - (float)game->pangle * 0.0174f));
	pix->dist = abs(game->c[4]);
	pix->angle = game->pangle * 0.0174f - pix->angle;
	while (pix->angle > M_PI)
		pix->angle -= 2 * M_PI;
	while (pix->angle < -M_PI)
		pix->angle += 2 * M_PI;
}

void			remp(t_game *game, t_pix *pix)
{
//	int i;
//	int j;
//	int k;

	game->c[2] = 0;
	while (game->c[2] < game->mapx * game->mapy)
		pix[game->c[2]++].dist = -1;
	game->c[1] = 0;
	game->c[3] = 0;
	while (game->c[1] < game->mapy)
	{
		game->c[2] = 0;
		while (game->c[2] < game->mapx)
		{
			if (game->map[game->c[1]][game->c[2]] == '2')
			{
				init_sprite(game, pix + game->c[3], game->c[1], game->c[2]);
				pix[game->c[3]].carac = game->map[game->c[1]][game->c[2]];
				game->c[3]++;
			}
			game->c[2]++;
		}
		game->c[1]++;
	}
	pixmodif(game, pix);
}

void			ft_remplir(t_game *game, float *dists)
{
	t_pix		pix[game->mapy * game->mapx];

	remp(game, pix);
	game->c[0] = 0;
	while (pix[game->c[0]].dist != -1)
	{
		drawspritee(game, dists, pix, game->c[0]);
		game->c[0]++;
	}
}
