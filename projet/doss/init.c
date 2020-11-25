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
	game.dx = 1;
	game.dy = 2;
    game.posx = 22;
	game.posy = 12;
	game.hit = 2;
	game.step = 1;
	return(game);
}

t_ray		ray_init(t_ray ray)
{
	ray.px = 0;
	ray.py = 0.66;
	return (ray);
}

void		var_init(int *time, int *oldtime, int *x, int *w)
{
	*time = 0;
	*oldtime = 0;
	*w = SCREENWIDTH;
	*x = 0;
}
