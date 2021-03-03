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

int			rcx(t_game *game, t_ray *ray, int count)
{
	char		ix;

	ray->var[0] = (game->pvar + 0.0174 / 2.0 - count * (40 / game->img.width[0])) * 0.0174;
	if (cos(ray->var[0]) == 0)
		return (-1);
	if (cos(ray->var[0]) > 0)
		ray->x[0] = ceil((float)(game->posx) / 64) * 64;
	else
		ray->x[0] = floor((float)(game->posx) / 64) * 64;
	ix = 'E';
	game->count[1] = 0;
	while (ix != '1' && game->count[1] < game->mapx)
	{
		ray->x[0] = ray->x[0] + (ix != 0 ? ft_signe(cos(ray->var[0])) * 64 : 0);
		ray->y[0] = abs((int)((game->posx - ray->x[0]) / cos(ray->var[0]))) * (-sin(ray->var[0])) + game->posy;
		ray->dist[0] = ft_dist(game->posy - ray->y[0], game->posx - ray->x[0]);
		if ((ray->y[0] + ft_signe(ray->y[0] - game->posy)) / 64 < game->mapy
			&& (ray->x[0] + ft_signe(ray->x[0] - game->posx)) / 64 < game->mapx)
		{
			ix = game->map[ft_max(0, (ray->y[0] + ft_signe(ray->y[0] - game->posy)) / 64)]
					[ft_max(0, (ray->x[0] + ft_signe(ray->x[0] - game->posx)) / 64)];
		}
		game->count[1]++;
	}
	if (ray->x[0] > game->posx)
		ray->flag[0] = 2;
	else
		ray->flag[0] = 3;
	ray->res[0] = (ix == '1');
	return (ray->res[0]);
}
