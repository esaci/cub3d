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
void			rcx(t_game *g,  int count)
{
	int			i;
	char		ix;

	g->ray.angle = (g->pangle + 40 / 2.0f - count * ((float)40 / g->ecranx)) * 0.0174f;
	ix = 'X';
	i = 0;
	if (cos(g->ray.angle) == 0)
		return ;
	g->ray.x[0] = cos(g->ray.angle) > 0 ? ceil((float)(g->posx) / 64) * 64 :
			floor((float)(g->posx) / 64) * 64;
	while (ix != '1' && i < g->mapx)
	{
		g->ray.x[0] = g->ray.x[0] + (i != 0 ? ft_signe(cos(g->ray.angle)) * 64 : 0);
		g->ray.y[0] = ft_abs((g->posx - g->ray.x[0]) / cos(g->ray.angle)) * (-sin(g->ray.angle)) + g->posy;
		g->ray.dist[0] = ft_dist(g->posy - g->ray.y[0], g->posx - g->ray.x[0]);
		if ((g->ray.y[0] + ft_signe(g->ray.y[0] - g->posy)) / 64 < g->mapy
			&& (g->ray.x[0] + ft_signe(g->ray.x[0] - g->posx)) / 64 < g->mapx)
		{
			ix = g->map[ft_max(0, (g->ray.y[0] + ft_signe(g->ray.y[0] - g->posy)) / 64)]
					[ft_max(0, (g->ray.x[0] + ft_signe(g->ray.x[0] - g->posx)) / 64)];
		}
		i++;
	}
	if (g->ray.x[0] > g->posx)
		g->ray.flag[0] = 3;
	else
		g->ray.flag[0] = 5;
/* 	if(g->c[1] <= 1)
		g->ray.flag[0] = 2; */
	g->ray.res[0] = (ix == '1');
	return ;
}

void			rcy(t_game *g)
{
	int			i;
	char		ix;

	i = 0;
	ix = 'X';
	if (sin(g->ray.angle) == 0)
		return ;
	g->ray.y[1] = sin(g->ray.angle) > 0 ? floor((float)(g->posy) / 64) * 64 :
			ceil((float)(g->posy) / 64) * 64;
	while (ix != '1' && i < g->mapy)
	{
		g->ray.y[1] = g->ray.y[1] - (i != 0 ? ft_signe(sin(g->ray.angle)) * 64 : 0);
		g->ray.x[1] = ft_abs((g->posy - g->ray.y[1]) / sin(g->ray.angle)) * (cos(g->ray.angle)) + g->posx;
		g->ray.dist[1] = ft_dist(g->posy - g->ray.y[1], g->posx - g->ray.x[1]);
		if ((g->ray.y[1] + ft_signe(g->ray.y[1] - g->posy)) / 64 < g->mapy
			&& (g->ray.x[1] + ft_signe(g->ray.x[1] - g->posx)) / 64 < g->mapx)
		{
			ix = g->map[ft_max(0, (g->ray.y[1] + ft_signe(g->ray.y[1] - g->posy)) / 64)]
				[ft_max(0, (g->ray.x[1] + ft_signe(g->ray.x[1] - g->posx)) / 64)];
		}
		i++;
	}
	if (g->ray.y[1] > g->posy)
		g->ray.flag[1] = 6;
	else
		g->ray.flag[1] = 4;
	if(g->c[1] <= 1)
		g->ray.flag[1] = 2;
	g->ray.res[0] = (ix == '1');
	return ;
}

/* 		if ((floor(g->ray.y[0]/64) + ft_max(0, ft_signe(g->ray.y[0] - g->posy)) < g->mapy)
			&& (floor(g->ray.x[0]/64) + ft_max(0,ft_signe(g->ray.x[0] - g->posx))) < g->mapx)
		{
			ix = g->map[ft_max(0, floor(g->ray.y[0]/64) + ft_max(0, ft_signe(g->ray.y[0] - g->posy)))]
					[ft_max(0, floor(g->ray.x[0]/64) + ft_max(0,ft_signe(g->ray.x[0] - g->posx)))];
		} */
