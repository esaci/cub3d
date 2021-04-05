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
	i = 0;
	while (i < game.mapy)
		free(game.map[i++]);
	free(game.map);
}

void		destroyernom(t_game *game, char *error, int i)
{
	while (i < 7)
	{
		if (ft_isprint(*(game->img.nom[i] + 3)) == 1)
			free(game->img.nom[i]);
		i++;
	}
	if (ft_strncmp(error,
		"Pas pu charger", 14) == 0)
	{
		i = 0;
		while (i < game->mapy)
			free(game->map[i++]);
		free(game->map);
		i = (ft_strncmp(error + 14, " la", 3) == 0) ? 2 : 7;
	}
	if (game->flag[3] == 1)
	{
		free(game->mlx.mlxptr);
		return ;
	}
	mlx_destroy_window(game->mlx.mlxptr, game->mlx.win);
	free(game->mlx.mlxptr);
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
