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

int		ft_windz(t_game *game)
{
	ft_stop(game, "aucun soucis");
	return (1);
}

int		ft_depart(t_game *g)
{
	float	dists[g->ecranx];

	initmlxptr(g, 7, g->ecranx, g->ecrany);
	game_init(g, 0);
	while (g->c[0] < g->ecranx)
	{
		g->ray.angle = ((g->pangle + (float)20) -
			(float)40 * ((float)g->c[0] / (float)g->ecranx)) * (float)0.0174;
		rcx(g, 1, 'E');
		if (!(sin(g->ray.angle) == 0))
			rcy(g, 0, 'E');
		dists[g->c[0]] = g->ray.dist[1];
		if ((g->ray.dist[1] < g->ray.dist[0]))
			drawrectimg(g, g->c[0], g->ray.x[1], 1);
		else
		{
			drawrectimg(g, g->c[0], g->ray.y[0], 0);
			dists[g->c[0]] = g->ray.dist[0];
		}
		g->c[0]++;
	}
	ft_sprite(g, dists);
	mlx_put_image_to_window(g->mlx.mlxptr
		, g->mlx.win, g->img.imgptr[7], 0, 0);
	return (mlx_destroy_image(g->mlx.mlxptr, g->img.imgptr[7]));
}
