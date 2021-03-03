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
		if(game->flag[2] == 1)
		{
			printf("gd->p_t %d _ rayangle %f _dist %d [1] - dist %d [0] ?\n", game->pangle, game->ray.angle[0], (int)game->ray.dist[1], (int)game->ray.dist[0]);
		}
		if ((game->ray.flag[1] != -1 && game->ray.dist[1] < game->ray.dist[0]))
		{
//			soucis ici quand je dep avec les murs qui s'affichent mal
			dists[game->c[0]] = game->ray.dist[1];
			drawrectimg2(game, game->c[0], game->ray.x[1], 1);
		}
		else
		{
			drawrectimg(game, game->c[0], game->ray.y[0], 0);
			dists[game->c[0]] = game->ray.dist[0];
		}
		game->c[0]++;
	}
//	ft_printf("\n posy %d \n g->ray.x[0] %d \n posx %d \n ray.y %d \n", game->posy, game->ray.x[0], game->posy, game->ray.y[0]);
//	ft_printf("dist %d [1] < dist %d [0] ?\n", (int)game->ray.dist[1], (int)game->ray.dist[0]);
//	ft_printf("dist %d \n", game->ray.dist[0]);
//	ft_printf("test %d \n", (int)ft_dist(5, 5));
	if(0 == 1)
		ft_remplir(game,dists);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[7],0,0);
	game->flag[2] = 0;
	return(mlx_destroy_image(game->mlx.mlxptr, game->img.imgptr[7]));
}
