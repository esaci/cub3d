/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:55:47 by esaci             #+#    #+#             */
/*   Updated: 2021/01/07 11:55:52 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

int		taillenval(int mapi, int j, t_game *game)
{
	int taille;

	taille = ft_strlen(game->map[game->c[mapi]]);
	if (taille != game->c[j] || taille > ROWS)
		return (1);
	return (0);
}

int		map_val_return(t_game *g, int len, int i)
{
	g->map_size_x = len;
	g->map_size_y = i;
	return (1);
}

int		bordurerectangle(t_game *game)
{
//	c[6]	i ;
//	c[2]	len;
//	c[5]	j;

	game->c[2] = ft_strlen(g->map[game->c[6]]);
	while (game->map[game->c[6]])
	{
		if (taillenval(6,2, game) || (game->c[6]++) * 0 != 0)
			ft_stop(game, "Taille de la map invalide");
		if(game->map[game->c[game->c[6]][0]] != '1' || game->map[game->c[game->c[6]][game->c[2]-1]] != '1')
			ft_stop(game, "La map n'est pas fermée a gauche ou a droite");
	}
	while (game->c[5] < game->c[2])
	{
		if ((int)game->map[0][game->c[5]] != '1' || (int)game->map[game->c[2] - 1][game->c[5]] != '1' || (game->c[5]++) * 0 == 0)
			ft_stop(game, "La map n'est pas fermée en haut ou en bas");
	}
	game->c[2] = 0;
	while (game->c[2] < game->c[6])
	{
		if (!(ft_only(g->map[game->c[2]++], "012NSWE")))
			ft_stop(game, "La map contient un mauvais symbole");
	}
	g->mapx = game->c[2];
	g->mapy = game->c[6];
	return (1);
}

int		map_validator_2(t_game *game, int i)
{
//  game->c[1] mapsize
//	game->c[7]		p;
//	game->c[8]		i;
//	game->c[9]		j;
//	game->c[10]		len;

	if (game->c[i] >= ROWS)
		return (error_message("map is too big", game, 1));
	while (game->map[i] != NULL)
	{
		j = 0;
		while (j < ROWS)
		{
			if (ft_inset_c(game->map[i][j], "NSEW"))
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (error_message("invalid map : too many players", game, 1));
	return (1);
}
