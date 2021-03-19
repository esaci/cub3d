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

float			ft_abs(float x)
{
	if (x < 0)
		x = x * (float)-1;
	return (x);
}

void			rcx(t_game *g, int wr, char ix)
{
	int			xr;
	int			yr;

	wr = cos(g->ray.angle) >= 0 ? 0 : 1;
	if (cos(g->ray.angle) == 0)
		return ;
	g->ray.x[0] = floor((float)(g->posx) / 64) * 64;
	if (cos(g->ray.angle) > 0)
		g->ray.x[0] = ceil((float)g->posx / 64) * 64;
	g->c[1] = 0;
	while (ix != '1' && g->c[1] < g->mapx)
	{
		if (g->c[1] != 0)
			g->ray.x[0] = g->ray.x[0] + ft_signe(cos(g->ray.angle)) * 64;
		g->ray.y[0] = g->posy + ft_abs((float)(g->posx - g->ray.x[0]) /
			(float)cos(g->ray.angle)) * (float)sin(g->ray.angle) * (-1);
		g->ray.dist[0] = ft_dist(g->posy - g->ray.y[0], g->posx - g->ray.x[0]);
		yr = (g->ray.y[0] + wr * ft_signe(g->ray.y[0] - g->posy)) / 64;
		xr = (g->ray.x[0] + wr * ft_signe(g->ray.x[0] - g->posx)) / 64;
		if (yr < g->mapy && xr < g->mapx)
			ix = g->map[ft_max(0, yr)][ft_max(0, xr)];
		g->c[1]++;
	}
	g->ray.flag[0] = g->ray.x[0] > g->posx ? 3 : 5;
}

void			rcy(t_game *g, int wr, char ix)
{
	int			xr;
	int			yr;

	wr = sin(g->ray.angle) > 0 ? 1 : 0;
	g->ray.y[1] = ceil((float)g->posy / 64) * 64;
	if (sin(g->ray.angle) > 0)
		g->ray.y[1] = floor((float)g->posy / 64) * 64;
	g->c[1] = 0;
	while (ix != '1' && g->c[1] < g->mapy)
	{
		if (g->c[1] != 0)
			g->ray.y[1] = g->ray.y[1] - ft_signe(sin(g->ray.angle)) * 64;
		g->ray.x[1] = g->posx + (ft_abs((float)(g->posy - g->ray.y[1]) /
			(float)sin(g->ray.angle)) * (float)cos(g->ray.angle));
		g->ray.dist[1] = ft_dist(g->posy - g->ray.y[1], g->posx - g->ray.x[1]);
		yr = (g->ray.y[1] + wr * ft_signe(g->ray.y[1] - g->posy)) / 64;
		xr = (g->ray.x[1] + wr * ft_signe(g->ray.x[1] - g->posx)) / 64;
		if (yr < g->mapy && xr < g->mapx)
			ix = g->map[ft_max(0, yr)][ft_max(0, xr)];
		g->c[1]++;
	}
	g->ray.flag[1] = g->ray.y[1] > g->posy ? 6 : 4;
	g->ray.res[1] = (ix == '1');
}
