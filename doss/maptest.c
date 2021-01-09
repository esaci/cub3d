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
	if (taille != game->c[j] || taille > COLS)
		return (1);
	return (0);
}

int		bordurerectangle(t_game *game)
{
	game->c[2] = ft_strlen(game->map[game->c[6]]);
	while (game->map[game->c[6]])
	{
		if (taillenval(6,2, game) || (game->c[6]++) * 0 != 0)
			ft_stop(game, "Taille de la map invalide(Soit c'est pas un rectangle, soit trop de colonne))");
		if(game->map[game->c[6]][0] != '1' || game->map[game->c[6]][game->c[2]-1] != '1')
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
		if (!(ft_only(game->map[game->c[2]++], "012NSWE")))
			ft_stop(game, "La map contient un mauvais symbole");
	}
	game->mapx = game->c[2];
	game->mapy = game->c[6];
	return (1);
}

int		nbrjoueurtligne(t_game *game, int i)
{
	int flagpl;

	flagpl = 0;
	if (!(game->c[i] < ROWS))
		ft_stop(game, "Trop de ligne dans la map");
	while (game->map[game->c[8]])
	{
		flagpl += ft_contient(game->map[game->c[8]], "NSWE");
		game->c[8]++;
	}
	if (flagpl == 0)
		ft_stop(game, "Pas de joueur");
	if (!(flagpl == 1))
		ft_stop(game, "Un/Plusieurs joueur en trop");
	return (1);
}
