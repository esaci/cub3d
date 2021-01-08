/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:05:17 by esaci             #+#    #+#             */
/*   Updated: 2020/11/29 18:05:20 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void			rcx(t_game *g,  int count)
{
	char		ix;

	g->ray->angle[0] = (game->pangle + 0.0174 / 2.0 - count * (40 / game->img.width[7])) * 0.0174;
	if (cos(g->ray->angle[0]) == 0)
		return ();
	if (cos(g->ray->angle[0]) > 0)
		g->ray->x[0] = ceil((float)(game->posx) / 64) * 64;
	else
		g->ray->x[0] = floor((float)(game->posx) / 64) * 64;
	ix = 'E';
	game->count[1] = 0;
	while (ix != '1' && game->count[1] < game->mapx)
	{
		g->ray->x[0] = g->ray->x[0] + (ix != 0 ? ft_signe(cos(g->ray->angle[0])) * 64 : 0);
		g->ray->y[0] = abs((int)((game->posx - g->ray->x[0]) / cos(g->ray->angle[0]))) * (-sin(g->ray->angle[0])) + game->posy;
		g->ray->dist[0] = ft_dist(game->posy - g->ray->y[0], game->posx - g->ray->x[0]);
		if ((g->ray->y[0] + ft_signe(g->ray->y[0] - game->posy)) / 64 < game->mapy
			&& (g->ray->x[0] + ft_signe(g->ray->x[0] - game->posx)) / 64 < game->mapx)
		{
			ix = game->map[ft_max(0, (g->ray->y[0] + ft_signe(g->ray->y[0] - game->posy)) / 64)]
					[ft_max(0, (g->ray->x[0] + ft_signe(g->ray->x[0] - game->posx)) / 64)];
		}
		game->count[1]++;
	}
	if (g->ray->x[0] > game->posx)
		g->ray->flag[0] = 2;
	else
		g->ray->flag[0] = 3;
	g->ray->res[0] = (ix == '1');
	return ();
}
