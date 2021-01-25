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

	g->ray.angle[0] = (g->pangle - count * ((float)40 / g->ecranx)) * 0.0174;
//	si il regarde vers la droite alors il regarde la case la plus proche c a dire en face
	if (cos(g->ray.angle[0]) > 0)
		g->ray.x[0] = ceil((float)(g->posx / 64)) * 64;
	if (cos(g->ray.angle[0]) < 0)
		g->ray.x[0] = floor((float)(g->posx / 64)) * 64;
	if (cos(g->ray.angle[0]) == 0)
		return ;
	g->c[1] = 0;
	ix = 'E';
	while (ix != '1' && g->c[1] < g->mapx)
	{
		if(count != 0)
			g->ray.x[0] = g->ray.x[0] + ft_signe(cos(g->ray.angle[0])) * 64;
		g->ray.y[0] = fabs((g->posx - g->ray.x[0]) / cos(g->ray.angle[0])) * (-sin(g->ray.angle[0])) + g->posy;
//		ft_printf("\n posy %d \n g->ray.x[0] %d \n posx %d \n ray.x %d \n", g->posy, g->ray.x[0], g->posy, g->ray.x[0]);
//		ft_printf("posx %d \n", g->posx);
		g->ray.dist[0] = ft_dist(g->posy - g->ray.y[0], g->posx - g->ray.x[0]);
//		ft_printf("cqui donne %d \n", (int)g->ray.dist[0]);
//		ca me fait avancer
		if ((g->ray.y[0] + ft_signe(g->ray.y[0] - g->posy)) / 64 < g->mapy
			&& (g->ray.x[0] + ft_signe(g->ray.x[0] - g->posx)) / 64 < g->mapx)
		{
			ix = g->map[ft_max(0, (g->ray.y[0] + ft_signe(g->ray.y[0] - g->posy)) / 64)]
					[ft_max(0, (g->ray.x[0] + ft_signe(g->ray.x[0] - g->posx)) / 64)];
		}
		g->c[1]++;
	}
	if (g->ray.x[0] > g->posx)
		g->ray.flag[0] = 2;
	else
		g->ray.flag[0] = 3;
	g->ray.res[0] = (ix == '1');
	return ;
}

void			rcy(t_game *g,  int count)
{
	char		ix;


	g->ray.angle[1] = (g->pangle  - count * ((float)40 / g->ecranx)) * 0.0174;
//	si il regarde vers devant alors il regarde la case la plus proche c a dire en face
	if (sin(g->ray.angle[1]) > 0)
		g->ray.y[1] = floor((float)(g->posy / 64)) * 64;
	if (sin(g->ray.angle[1]) < 0)
		g->ray.y[1] = ceil((float)(g->posy / 64)) * 64;
	if (sin(g->ray.angle[1]) == 0)
		return;
	g->c[1] = 0;
	ix = 'E';
	while (ix != '1' && g->c[1] < g->mapy)
	{
		if(count != 0)
			g->ray.y[1] = g->ray.y[1] - ft_signe(sin(g->ray.angle[1])) * 64;
		g->ray.x[1] = fabs(((g->posy - g->ray.y[1]) / sin(g->ray.angle[1]))) * (cos(g->ray.angle[1])) + g->posx;
//		ft_printf(" test val %d vs %d //  \n", g->ray.x[1], g->ray.y[1]);
		g->ray.dist[1] = ft_dist(g->posy - g->ray.y[1], g->posx - g->ray.x[1]);
//		CA ME FAIT AVANCER
		if ((g->ray.y[1] + ft_signe(g->ray.y[1] - g->posy)) / 64 < g->mapy
			&& (g->ray.x[1] + ft_signe(g->ray.x[1] - g->posx)) / 64 < g->mapx)
		{
			ix = g->map[ft_max(0, (g->ray.y[1] + ft_signe(g->ray.y[1] - g->posy)) / 64)]
					[ft_max(0, (g->ray.x[1] + ft_signe(g->ray.x[1] - g->posx)) / 64)];
		}
		g->c[1]++;
	}
	if (g->ray.x[1] > g->posx)
		g->ray.flag[1] = 0;
	else
		g->ray.flag[1] = 1;
	g->ray.res[1] = (ix == '1');
//	ft_printf("cqui donne en distance [1] %d \n", g->ray.dist[1]);
	return ;
}
