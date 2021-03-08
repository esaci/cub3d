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
		rcy(game);
		if(game->flag[2] == 1 && (game->ray.dist[1] >= game->ray.dist[0]) && (game->ray.flag[0] == 5))
		{
			printf("----------------------------------------------------------------- \n");
			printf("Position : X %d/%d -  Y %d/%d\n", game->posx / 64, game->mapx , game->posy / 64, game->mapy);
			printf("Pos Murcoté [0] : %f\nPos Murligne[0] : %f\n",(float)((game->ray.x[0] ) - game->posx) / 64 , (float)(game->ray.y[0] - game->posy)/64);
			printf("Pos Murcoté [1] : %f\nPos Murligne[1] : %f\n", (float)((game->ray.x[1] ) - game->posx) / 64 , (float)(game->ray.y[1] - game->posy)/64);
			printf("Pos Murcoté [0] : %d\nPos Murligne[0] : %d\n", (game->ray.x[0] )/64, (game->ray.y[0] )/64);
			printf("Pos Murcoté [1] : %d\nPos Murligne[1] : %d\n", (game->ray.x[1] ) /64 , (game->ray.y[1] )/64);
			printf("Angle :  %d° \nAngle Ecran : %f° \n", game->pangle, game->ray.angle*(1/0.0174));
 			printf("Cos Angle ecran : %f\nSin Angle ecran : %f\n", cos(game->ray.angle), sin(game->ray.angle));
			printf("Distance[0] : %f \nDistance[1] : %f \n", game->ray.dist[0] / 64, game->ray.dist[1] / 64);
			printf("Case 1 : %d/%d\n", (game->ray.x[1] + ft_signe(game->ray.x[1] - game->posx)) / 64 , (game->ray.y[1] + ft_signe(game->ray.y[1] - game->posy)) / 64);
			printf("----------------------------------------------------------------- \n\n");
		}
		if ((game->ray.dist[1] < game->ray.dist[0]) && game->ray.res[0] == 1)
		{
			dists[game->c[0]] = game->ray.dist[1];
			drawrectimg(game, game->c[0], game->ray.x[1], 1);
		}
		else
		{
			drawrectimg(game, game->c[0], game->ray.y[0], 0);
			dists[game->c[0]] = game->ray.dist[0];
		}
		game->c[0]++;
	}
	if(0 == 1)
		ft_remplir(game,dists);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[7],0,0);
	game->flag[2] = 0;
	return(mlx_destroy_image(game->mlx.mlxptr, game->img.imgptr[7]));
}
