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
	int		i;
	int		j;

	i = 54;
	j = 0;
	while (i < game->ecrany * game->ecranx * 4 + 54)
	{
		if (i)
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
	while (j < 4)
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
	char	*str2;

	np = game->ecranx * game->ecrany * 4;
	if (!(fd1 = open(nomfichier, O_CREAT | O_TRUNC | O_RDWR, 0777)))
		ft_stop(game, "Pas reussi a creer le bmp");
	if (!(str = malloc(sizeof(char) * (np + 100))))
		ft_stop(game, "Malloc fonctionne pas creation du bmp");
	headbmp(game, str, np);
	np = databmp(str, game);
	if (!(str2 = malloc(sizeof(unsigned char) * 10)))
		ft_stop(game, "mallox str2 bloqué");
	swapbmp(game, (str + 53), 0, str2);
	write(fd1, str, np);
	free(str);
}

int		ft_bmp(t_game *g)
{
	float	dists[g->ecranx];

	initmlxptr(g, 7, g->ecranx, g->ecrany);
	game_init(g, 0);
	while (g->c[0] < g->ecranx)
	{
		g->ray.angle = ((g->pangle + (float)20) -
			(float)40 * ((float)g->c[0] / (float)g->ecranx)) * (float)0.0174f;
		rcx(g, 1, 'E');
		if (!(sin(g->ray.angle) == 0))
			rcy(g, 0, 'E');
		dists[g->c[0]] = g->ray.dist[1];
		if ((g->ray.dist[1] < g->ray.dist[0]) && g->ray.res[1] == 1)
			drawrectimg(g, g->c[0], g->ray.x[1], 1);
		else
		{
			drawrectimg(g, g->c[0], g->ray.y[0], 0);
			dists[g->c[0]] = g->ray.dist[0];
		}
		g->c[0]++;
	}
	ft_sprite(g, dists);
	createbmp(g, "result.bmp");
	return (1);
}
