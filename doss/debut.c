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
//	float	dists[g->screen_x];

	initmlxptr(game, 7, game->ecranx, game->ecrany);
	while (game->c[0] < game->ecranx)
	{
		rcx(game, game->c[0]);
		rcy(game, game->c[0]);
		if (ry.valid != -1 && ry.dist < rx.dist && (dists[game->c[0]] = ry.dist))
			draw_column(g, &ry,game->c[0], ry.hx);
		else
		{
			draw_column(g, &rx,game->c[0], rx.hy);
			dists[game->c[0]] = rx.dist;
		}
		game->c[0]++;
	}
	render_sprites(g, dists);
	write_bmp("full.bmp", g);
	g->window = NULL;
	destroy_game_data_full(g, 1);
}
