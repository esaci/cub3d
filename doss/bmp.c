/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:52:26 by esaci             #+#    #+#             */
/*   Updated: 2021/03/12 16:52:29 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

int		databmp(char *str, t_game *game)
{
	int	i;
	int	j;

	i = 54;
	j = 0;
	while (i < game->ecrany * game->ecranx * 4 + 54)
	{
		if(i)
		str[i] = (unsigned char)game->img.data[7][j];
		i++;
		j++;
	}
	return (i);
}

void	divid(char *str, int *i, int np)
{
	int		j;

	j = 0;
	while(j < 4)
	{
		str[*i] = np % 256;
		np = np / 256;
		j++;
		*i = *i + 1;
	}
}



void	createbmp(t_game *game, char *nomfichier)
{
	int		np;
	int		fd1;
	char	*str;

	np = game->ecranx * game->ecrany * 4;
	if(!(fd1 = open(nomfichier, O_CREAT | O_TRUNC | O_RDWR, 0777)))
		ft_stop(game, "Pas reussi a creer le bmp");
	if (!(str = malloc(sizeof(char) * (np + 55))))
		ft_stop(game, "Malloc fonctionne pas creation du bmp");
	headbmp(game, str, np);
	np = databmp(str, game);
	swapbmp(game, str);
	write(fd1, str, np);
	free(str);
}

int		ft_bmp(t_game *game)
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
	createbmp(game, "result.bmp");
	return(1);
}
