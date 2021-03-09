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

void			loadsprite(t_game *game, t_sprite *s, int ligne, int col)
{
	s->x = col * 64 + 32;
	s->y = ligne * 64 + 32;
	s->dist = ft_dist((float)(game->posy - s->y), (float)(game->posx - s->x));
	if (s->dist == 0)
		s->angle = 0;
	/* arcsin renvoie l'angle en rad grace au rapport distance parcourue sur y / distance parcourue */
	/* arcsin(opposé/hypotenuse) :> angle */
/* 	pas compris le deuxieme elseif */
/* 	si le sprite est plus a gauche de nous alors */
	else if (s->x >= game->posx)
		s->angle = asin((game->posy - s->y) / s->dist);
	else
		s->angle = -asin((game->posy - s->y) / s->dist) + M_PI;
	game->c[14] = s->dist * (cos(s->angle - (float)game->pangle * 0.0174f));
	s->dist = abs(game->c[4]);
	s->angle = game->pangle * 0.0174f - s->angle;
	while (s->angle > M_PI)
		s->angle -= 2 * M_PI;
	while (s->angle < -M_PI)
		s->angle += 2 * M_PI;
}

void			cherchesprite(t_game *game, t_sprite *s)
{
//	int i;
//	int j;
//	int k;

	game->c[11] = 0;
	while (game->c[11] < game->mapx * game->mapy)
		pix[game->c[11]++].dist = -1;
	game->c[11] = 0;
	game->c[12] = 0;
	game->c[13] = 0;
	while (game->c[11] < game->mapy)
	{
		game->c[12] = 0;
		while (game->c[12] < game->mapx)
		{
			if (game->map[game->c[11]][game->c[12]] == '2')
			{
				loadsprite(game, s[game->c[13]], game->c[11], game->c[12]);
				game->c[13]++;
			}
			game->c[2]++;
		}
		game->c[1]++;
	}
/* 	ici------------------------------------------------------------------------------------------ */
	pixmodif(game, pix);
}

void			ft_sprite(t_game *game, float *dists)
{
	t_sprite	s[game->mapy * game->mapx];

/* 	game->c[11] : [0, mapy]
	game->c[12] : [0, mapx]
	game->c[13] : [0, nbr de sprite]
	game->c[10] : [0, jsp] */
	game->c[10] = 0;
	cherchesprite(game, pix);
	while (pix[game->c[10]].dist != -1)
	{
		drawspritee(game, dists, pix, game->c[0]);
		game->c[0]++;
	}
}
