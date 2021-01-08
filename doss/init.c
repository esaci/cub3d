/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:03:36 by esaci             #+#    #+#             */
/*   Updated: 2020/11/22 16:04:04 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"


void		game_init(t_game *game, int mode)
{
	int i;
	i = 0;
	while(i < NBRCOUNT && (i++) * 0 == 0)
		game->c[i] = 0;
	if (mode = 1)
		return ();
	game->flag[0] = 0;
	game->ph = 53;
//	game->vise = 0;
//	game->dx = -1;
//	game->dy = 0;
//	game->posx = 9;
//	game->posy = 9;
//	game->planex = 0;
//	game->planey = 0.66;
//	game->hit = 4;
//	game->step = 1;
//	game->mapx = SCREENWIDTH;
//	game->mapy = SCREENHEIGHT;
}

t_ray		ray_init(t_ray ray)
{
	return (ray);
}

void	window_init(t_game *game)
{
	game->mlx.mlxptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlxptr, SCREENWIDTH, SCREENHEIGHT, "fenetre init");

}
