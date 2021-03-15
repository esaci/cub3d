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


void	ft_show(t_game *game)
{
	int		c;
	int		s;
	int		temp[4];

	c = ft_signe(cos(game->ray.angle));
	s = ft_signe(sin(game->ray.angle));
	temp[0] = ft_max(0, game->ray.x[0] / 64);
	temp[1] = ft_max(0, game->ray.y[0] / 64);
	temp[2] = ft_max(0, game->ray.x[1] / 64);
	temp[3] = ft_max(0, game->ray.y[1] / 64);
	if(game->ray.dist[1] < game->ray.dist[0] && c + s < 10 && game->ray.res[1] == 1)
	{
		if(temp[1] > game->mapy || temp[0] > game->mapx)
			return;
 		if (game->map[temp[1]][temp[0]] == '1')
			game->ray.flag[1] = game->ray.flag[1];
		else
			game->ray.flag[1] = game->ray.flag[0];
	}
	else
	{
	if(temp[3] > game->mapy || temp[2] > game->mapx)
			return;
	if (game->map[temp[3]][temp[2]] == '1')
		game->ray.flag[0] = game->ray.flag[0];
	else
			game->ray.flag[0] = game->ray.flag[1];
	}
}

int		ft_depart(t_game *game)
{
	float	dists[game->ecranx];

	initmlxptr(game, 7, game->ecranx, game->ecrany);
	game_init(game, 0);
	while (game->c[0] < game->ecranx)
	{
		rcx(game, game->c[0]);
		rcy(game);
		if ((game->ray.dist[1] < game->ray.dist[0]) && game->ray.res[1] == 1)
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
	ft_sprite(game,dists);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[7],0,0);
	game->flag[2] = 0;
	return(mlx_destroy_image(game->mlx.mlxptr, game->img.imgptr[7]));
}
