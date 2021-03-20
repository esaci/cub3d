/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:32:30 by esaci             #+#    #+#             */
/*   Updated: 2020/11/29 12:32:32 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void		destroyer(t_game game, int j, ...)
{
	va_list		elias;
	int			i;

	va_start(elias, j);
	while (j > 0)
	{
		i = va_arg(elias, int);
		mlx_destroy_image(game.mlx.mlxptr, game.img.imgptr[i]);
		j--;
	}
	va_end(elias);
}

void		destroyernom(t_game *game)
{
	int i;

	i = 0;
	while (i <= 1)
		free(game->img.datac[i]);
	while (i <= 7)
		free(game->img.nom[i++]);
	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

void		modifdxdy(t_game *game, int i, int dx, int dy)
{
	game->img.dx[i] = dx;
	game->img.dy[i] = dy;
}

void		modifhw(t_game *game, int i, int height, int width)
{
	game->img.height[i] = height;
	game->img.width[i] = width;
}

int			ft_signe(float x)
{
	int y;

	y = 0;
	if (x < 0)
		y = -1;
	if (x > 0)
		y = 1;
	return (y);
}
