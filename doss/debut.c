/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:05:42 by esaci             #+#    #+#             */
/*   Updated: 2021/01/08 13:06:15 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

int		ft_depart(t_game *game)
{
	float	dists[game->ecranx];

	initmlxptr(game, 7, game->ecranx, game->ecrany);
	game_init(game, 0);
	while (game->c[0] < game->ecranx)
	{
		rcx(game, game->c[0]);
		rcy(game, game->c[0]);
		if (game->ray.flag[1] != -1 && game->ray.dist[1] < game->ray.dist[0])
		{
			drawrectimg(game, game->c[0], 1);
			dists[game->c[0]] = game->ray.dist[1];
		}
		else
		{
			drawrectimg(game, game->c[0], 0);
			dists[game->c[0]] = game->ray.dist[0];
		}
		game->c[0]++;
	}
	if(0 == 1)
		ft_remplir(game,dists);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[7],0,0);
	return(mlx_destroy_image(game->mlx.mlxptr, game->img.imgptr[7]));
}
