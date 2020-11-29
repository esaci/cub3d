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

int			raycast_x(t_game *game, t_ray ray, int c, char object)
{
	char		cell;

	cell = 'X';
	game->count = 0;
	ray.t = (gd->p_t + TETA / 2.0f - c * ((float)TETA / gd->screen_x)) * RAD;
	if (cos(r->t) == 0)
		return (-1);
	r->hx = cos(r->t) > 0 ? ceil((float)(gd->p_x) / CELL) * CELL :
			floor((float)(gd->p_x) / CELL) * CELL;
	while (cell != object && i < gd->map_size_x)
	{
		r->hx = r->hx + (i != 0 ? sign(cos(r->t)) * CELL : 0);
		r->hy = abs((gd->p_x - r->hx) / cos(r->t)) * (-sin(r->t)) + gd->p_y;
		r->dist = ft_dist(gd->p_y - r->hy, gd->p_x - r->hx);
		if ((r->hy + sign(r->hy - gd->p_y)) / CELL < gd->map_size_y
			&& (r->hx + sign(r->hx - gd->p_x)) / CELL < gd->map_size_x)
		{
			cell = gd->map[ft_max(0, (r->hy + sign(r->hy - gd->p_y)) / CELL)]
					[ft_max(0, (r->hx + sign(r->hx - gd->p_x)) / CELL)];
		}
		i++;
	}
	r->txt = r->hx > gd->p_x ? 2 : 3;
	return (r->valid = (cell == object));
}
