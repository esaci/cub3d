/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:48:19 by esaci             #+#    #+#             */
/*   Updated: 2020/11/29 15:48:25 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

int			setuped(t_game *game)
{
	modifhw(game, 0, SCREENHEIGHT, SCREENWIDTH);
	initmlxptr(game, 0, game->img.width[0], game->img.height[0]);
	game->count = 0;
	while (game->count < game->img.width[0])
	{
		raycast_x(g, &rx, game->count, '1');
		raycast_y(g, &ry, game->count, '1');
		if (ry.valid != -1 && ry.dist < rx.dist && (dists[i] = ry.dist))
			draw_column(g, &ry, i, ry.hx);
		else
		{
			draw_column(g, &rx, i, rx.hy);
			dists[i] = rx.dist;
		}
		game->count++;
	}
	render_sprites(g, dists);
	mlx_put_image_to_window(game->mlx.mlxptr , game->mlx.win, game->img.imgptr[0], 0, 0);
	return (mlx_destroy_image(game.>mlx.win , game->img.imgptr[0]));
}
