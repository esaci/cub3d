/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:49:05 by esaci             #+#    #+#             */
/*   Updated: 2021/01/12 14:49:08 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void			ft_ordre(t_game *game, t_pix *pix)
{
	game->c[0] = 1;
	while (game->c[0])
	{
		game->c[0] = 0;
		game->c[1] = 0;
		while (pix[game->c[1] + 1].dist != -1)
		{
			if (pix[game->c[1] + 1].dist > pix[game->c[1]].dist)
			{
				swap_data((pix + game->c[1] + 1), (pix + game->c[1]));
				game->c[0] = 1;
				game->c[1] = 0;
			}
			game->c[1]++;
		}
	}
}


void			set_sprite_struct(t_game *g, t_pix *pix, int i, int j)
{
	// on fera apres
	float	temp;

	pix->x = j * CELL + CELL / 2;
	pix->y = i * CELL + CELL / 2;
	pix->dist = ft_dist((float)(g->p_y - pix->y), (float)(g->p_x - pix->x));
	if (pix->dist == 0)
		pix->teta = 0;
	else if (pix->x >= g->p_x)
		pix->teta = asin((g->p_y - pix->y) / pix->dist);
	else
		pix->teta = -asin((g->p_y - pix->y) / pix->dist) + M_PI;
	temp = pix->dist * (cos(pix->teta - (float)g->p_t * RAD));
	pix->dist = abs(temp);
	pix->teta = g->p_t * RAD - pix->teta;
	while (pix->teta > M_PI)
		pix->teta -= 2 * M_PI;
	while (pix->teta < -M_PI)
		pix->teta += 2 * M_PI;
}


void			ft_objet(t_game *game, t_pix *pix)
{
	game->c[0] = 0;
	while (game->c[0] < game->mapx * game->mapy)
		pix[game->c[0]++].dist = -1;
	game->c[2] = 0;
	game->c[0] = 0;
	while (game->c[0] < game->mapy)
	{
		game->c[1] = 0;
		while (game->c[1] < game->mapx)
		{
			if (game->map[game->c[0]][game->c[1]] == '2')
			{
				ft_stop(game, "retire l'objet");
/*				set_sprite_struct(g, pix + game->c[2], game->c[0], game->c[1]);
				pix[game->c[2]].type = game->map[game->c[0]][game->c[1]];
				game->c[2]++;
*/
			}
			game->c[1]++;
		}
		game->c[0]++;
	}
	ft_ordre(game, pix);
}

void			ft_dessin(t_game *game, float *dists)
{
	int			i;
	t_pix		pix[game->mapx * game->mapy];

	ft_objet(game, pix);
	i = 0;
	while (pix[i].dist != -1)
		i++;
}
