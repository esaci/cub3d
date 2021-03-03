/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:10:00 by esaci             #+#    #+#             */
/*   Updated: 2020/12/27 22:10:05 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void		drawcol(t_game *game, t_ray *ray, int col, int hit)
{
	float		dist;
	int			height;
	t_pix		pix;

	dist = abs((int)(ray->dist[0] * cos((ray->var[0] - (float)game->pvar * 0.0174f))));
	height = ceil(150 * game->mapy / dist);
	pix.x = col;
	pix.flag = hit;
	pix.y = 0;
	while (pix.y++ < (game->mapy - height) / 2)
		drawpix(game, 0, pix, (unsigned char*)game->img.data[2]);
	while (pix.y < (game->mapy + height) / 2 && pix.y++ < game->mapy)
		drawpix(game, 0, pix, (unsigned char*)game->img.data[1]);
	while (pix.y++ < (game->mapy))
		drawpix(game, 0, pix, (unsigned char*)game->img.data[3]);
}
