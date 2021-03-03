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

t_game		game_init(t_game game)
{
	game.vise = 0;
	game.dx = -1;
	game.dy = 0;
	game.posx = 9;
	game.posy = 9;
	game.planex = 0;
	game.planey = 0.66;
	game.hit = 4;
	game.step = 1;
	game.flag = 0;
	game.mapx = SCREENWIDTH;
	game.mapy = SCREENHEIGHT;
	return(game);
}

t_ray		ray_init(t_ray ray)
{
	return (ray);
}

void		var_init(t_game *game)
{
	game->time = 0;
	game->oldtime = 0;
}
