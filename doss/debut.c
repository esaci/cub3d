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

void		ft_depart(t_game *game)
{
//	int		i;
//	t_ray	rx;
//	t_ray	ry;
	float	dists[game->ecranx];

	initmlxptr(game, 7, game->ecranx, game->ecrany);
	while (game->c[0] < game->ecranx)
	{
		rcx(game, game->c[0]);
		rcy(game, game->c[0]);
		if (game->ray.flag[1] != -1 && game->ray.dist[1] < game->ray.dist[0] && (dists[game->c[0]] = game->ray.dist[1]))
			drawrectimg(game, game->c[0], 1);
		else
		{
			drawrectimg(game, game->c[0], 0);
			dists[game->c[0]] = game->ray.dist[0];
		}
		game->c[0]++;
	}
	ft_stop(game, "tout est bon");
}
