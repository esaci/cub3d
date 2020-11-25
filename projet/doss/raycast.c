/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:18:46 by esaci             #+#    #+#             */
/*   Updated: 2020/11/22 16:18:49 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void    raycat(t_game *game, t_ray *ray, int *x, int *w)
{
// calcul pour chaque ligne verticale, ca commence a la (ray.px, ray.py)
// camerax est la projection de ray.px sur le plan, avec ce calcul tout a gauche -1, milieu 0 et a droite a gauche
//
	while (*x < *w)
	{
		game->camerax = 2 * (*x) / (*w) - 1;
		ray->raydirx = game->dx + ray->px * game->camerax;
		ray->raydiry = game->dy + ray->py * game->camerax;
		x++;
	}
	// mapx et et mapy rpz le carre ou est lobjet quon ray c donc entier
	// sidedistx et sidedisty distance entre lobjet et le premiere entier x ou entier y
	// deltadistx et deltadisty c d'un entier x et y a l'autre entier
	game->mapx = (int)(game->posx);
	game->mapy = (int)(game->posy);
	ray->deltadistx = abs(1 / ray->raydirx);
	ray->deltadisty = abs(1 / ray->raydiry);
	game->hit = 0;

	if (ray->raydirx < 0)
	{
		game->step = -1;
		ray->sidedistx = (game->posx - game->mapx) * ray->deltadistx;
	}
	else
	{
		game->stepx = 1;
		ray->sidedistx = (game->mapx + 1 - game->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		game->step = -1;
		ray->sidedisty = (game->posy - game->mapy) * ray->deltadisty;
	}
	else
	{
		game->stepy = 1;
		ray->sidedisty = (game->mapy + 1 - game->posy) * ray->deltadisty;
	}
// tant qu'n a rien tape, on avance, si on tape tout stop et side vaut 0 si on bouge en x sinon 1 et bouge en y
	while (game->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			game->mapx += game->stepx;
			game->side = 0;
		}
		else {
			ray->sidedisty += ray->deltadisty;
			game->mapy += game->stepy;
			game->side = 1;
		}
		if (game->map[game->mapx][game->mapy] > 0)
			game->hit = 1;
	}
// perpwalldist taille de la ligne perpendiculaire a mon plan de camera et touche h, le point qui est raycast, MTN dIFF x ET y ?
	if(game->side == 0)
		ray->perpwalldist = (game->mapx - game->posx + (1 - game->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (game->mapy - game->posy + (1 - game->stepy) / 2) / ray->raydiry;
// taille de la ligne direct entre la pos et le point qui est raycast
	ray->lineheight = (int)(game->vise / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + game->vise / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + game->vise / 2;
	if (ray->drawend < 0)
		ray->drawend = game->vise - 1;

}
