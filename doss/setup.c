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

int			setuped(t_game *game, t_ray *ray)
{
	initmlxptr(game, 0, game->img.width[0], game->img.height[0]);
	game->count[0] = 0;
	while (game->count[0] < game->img.width[0])
	{
		rcx(game, ray, game->count[0]);
		if (ray->res[0] != -1 && ray->dist[1] < ray->dist[0] && (game->dstncs[game->count[0]] = ray->dist[1]))
			drawcol(game, ray, game->count[0], 1);
		else
		{
			drawcol(game, ray, game->count[0], 0);
			game->dstncs[game->count[0]] = ray->dist[0];
		}
		game->count[0]++;
	}
//	render_sprites(g, dists);
	mlx_put_image_to_window(game->mlx.mlxptr , game->mlx.win, game->img.imgptr[0], 0, 0);
	return (mlx_destroy_image(game->mlx.win , game->img.imgptr[0]));
}
