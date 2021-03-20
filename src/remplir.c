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

void			swapper(t_sprite *s1, t_sprite *s2)
{
	t_sprite swap;

	swap.x = s1->x;
	swap.y = s1->y;
	swap.angle = s1->angle;
	swap.dist = s1->dist;
	s1->y = s2->y;
	s1->x = s2->x;
	s1->dist = s2->dist;
	s1->angle = s2->angle;
	s2->dist = swap.dist;
	s2->x = swap.x;
	s2->y = swap.y;
	s2->angle = swap.angle;
}

void			sorder(t_game *game, t_sprite *s)
{
	game->c[15] = 1;
	game->c[16] = 0;
	while (game->c[15])
	{
		game->c[15] = 0;
		game->c[16] = 0;
		while (s[game->c[6] + 1].dist != -'E')
		{
			if (s[game->c[6] + 1].dist > s[game->c[6]].dist)
			{
				swapper((s + game->c[6] + 1), (s + game->c[6]));
				game->c[15] = 1;
				game->c[16] = 0;
			}
			game->c[6]++;
		}
	}
}

void			loadsprite(t_game *game, t_sprite *s, int ligne, int col)
{
	s->x = col * 64 + 30;
	s->y = ligne * 64 + 30;
	s->dist = ft_dist((float)(game->posy - s->y), (float)(game->posx - s->x));
	if (s->dist == 0)
		s->angle = 0;
	if (s->x >= game->posx)
		s->angle = asin((game->posy - s->y) / s->dist);
	else
		s->angle = M_PI - asin((game->posy - s->y) / s->dist);
	game->c[14] = s->dist * (cos(s->angle - (float)game->pangle * 0.0174f));
	s->dist = abs(game->c[14]);
	s->angle = game->pangle * 0.0174f - s->angle;
	while (s->angle > M_PI)
		s->angle -= 2 * M_PI;
	while (s->angle < -M_PI)
		s->angle += 2 * M_PI;
}

void			cherchesprite(t_game *game, t_sprite *s)
{
	game->c[11] = 0;
	while (game->c[11] < game->mapx * game->mapy)
		s[game->c[11]++].dist = -'E';
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
				loadsprite(game, s + game->c[13], game->c[11], game->c[12]);
				game->c[13]++;
			}
			game->c[12]++;
		}
		game->c[11]++;
	}
	sorder(game, s);
}

void			ft_sprite(t_game *game, float *dists)
{
	t_sprite	s[game->mapy * game->mapx];

	game->c[10] = 0;
	cherchesprite(game, s);
	while (s[game->c[10]].dist != -'E')
	{
		drawsprite(game, dists, s);
		game->c[10]++;
	}
}
