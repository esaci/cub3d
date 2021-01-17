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
	while (i < NBRCOUNT)
		game->c[i++] = 0;
	if (mode == 1)
		return ;
	game->flag[0] = 0;
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
