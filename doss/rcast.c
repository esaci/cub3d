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

/* void			ft_coin(t_game *g, int ix)
{
	return;
	if(ix == '1' && g->ray.dist[1] < g->ray.dist[0] && g->map[ft_max(0, yr)][ft_max(0, xr - ft_signe(g->ray.x[1] - g->posx))] == '1')

	if(ix == '1' && g->ray.dist[1] >= g->ray.dist[0] && g->map[ft_max(0, yr - ft_signe(g->ray.y[1] - g->posy))][ft_max(0, xr)] == '1')
	g->ray.flag[1] = g->ray.flag[(int)ft_abs(1 -1)];
} */

float			ft_abs(float x)
{
	if (x < 0)
		x = x * (float)-1;
	return (x);
}
void			rcx(t_game *g,  int count)
{
	char		ix;
	int			xr;
	int			yr;
	int			wr;

	wr = 1;
	if(cos(g->ray.angle) >= 0)
		wr = 0;
	g->ray.angle = ((g->pangle + (float)20) - (float)40 * ((float)count / (float)g->ecranx)) * (float)0.0174f;
	if (cos(g->ray.angle) == 0)
		return;
	if (cos(g->ray.angle) > 0)
		g->ray.x[0] = ceil((float)g->posx / 64) * 64;
	if (cos(g->ray.angle) < 0)
		g->ray.x[0] = floor((float)(g->posx) / 64) * 64;
	g->c[1] = 0;
	ix = 'E';
	while (ix != '1' && g->c[1] < g->mapx)
	{
		if(g->c[1] != 0)
			g->ray.x[0] = g->ray.x[0] + ft_signe(cos(g->ray.angle)) * 64;
		g->ray.y[0] = g->posy + ft_abs((float)(g->posx - g->ray.x[0]) / (float)cos(g->ray.angle)) * (float)sin(g->ray.angle) * (-1);
		g->ray.dist[0] = ft_dist(g->posy - g->ray.y[0], g->posx - g->ray.x[0]);
		yr = (g->ray.y[0] + wr * ft_signe(g->ray.y[0] - g->posy)) / 64;
		xr = (g->ray.x[0] + wr * ft_signe(g->ray.x[0] - g->posx)) / 64;
		if (yr < g->mapy && xr < g->mapx)
			ix = g->map[ft_max(0, yr)][ft_max(0, xr)];
		g->c[1]++;
	}
	if (g->ray.x[0] > g->posx)
		g->ray.flag[0] = 3;
	else
		g->ray.flag[0] = 5;
	g->ray.res[0] = (ix == '1');
	return ;
}

void			rcy(t_game *g)
{
	char		ix;
	int			xr;
	int			yr;
	int			wr;

	wr = 0;
	if (sin(g->ray.angle) > 0)
		wr = 1;
	if (sin(g->ray.angle) == 0)
		return;
	if (sin(g->ray.angle) > 0)
		g->ray.y[1] = floor((float)g->posy / 64) * 64;
	if (sin(g->ray.angle) < 0)
		g->ray.y[1] = ceil((float)g->posy / 64) * 64;
	g->c[1] = 0;
	ix = 'E';
	g->ray.x[1] = 0;
	while (ix != '1' && g->c[1] < g->mapy)
	{
		if(g->c[1] != 0)
			g->ray.y[1] = g->ray.y[1] - ft_signe(sin(g->ray.angle)) * 64;
		g->ray.x[1] = g->posx + (ft_abs((float)(g->posy - g->ray.y[1]) / (float)sin(g->ray.angle)) * (float)cos(g->ray.angle));
		g->ray.dist[1] = ft_dist(g->posy - g->ray.y[1], g->posx - g->ray.x[1]);
		yr = (g->ray.y[1] + wr * ft_signe(g->ray.y[1] - g->posy)) / 64;
		xr = (g->ray.x[1] + wr * ft_signe(g->ray.x[1] - g->posx)) / 64;
		if (yr < g->mapy && xr < g->mapx)
			ix = g->map[ft_max(0, yr)][ft_max(0, xr)];
		g->c[1]++;
	}
	if (g->ray.y[1] > g->posy)
		g->ray.flag[1] = 6;
	else
		g->ray.flag[1] = 4;
	g->ray.res[1] = (ix == '1');
	return ;
}
