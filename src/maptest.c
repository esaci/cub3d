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

int			taillenval(int mapi, int j, t_game *game)
{
	int taille;

	taille = ft_strlen(game->map[game->c[mapi]]);
	if (taille != game->c[j] || taille > COLS)
		return (1);
	return (0);
}

void		bordurerectangle(t_game *game)
{
	game->c[2] = ft_strlen(game->map[game->c[6]]);
	game->mapx = game->c[2];
	while (game->map[game->c[6]])
	{
		if (taillenval(6, 2, game))
			game->ecranx = 11;
		if (game->map[game->c[6]][0] != '1'
			|| game->map[game->c[6]][game->c[2] - 1] != '1')
			game->ecranx = 11;
		game->c[6]++;
	}
	game->mapy = game->c[6];
	while (game->c[5] < game->c[2])
	{
		if ((int)game->map[0][game->c[5]] != '1'
			|| (int)game->map[game->c[1] - 1][game->c[5]] != '1')
			game->ecranx = 11;
		game->c[5]++;
	}
	game->c[2] = 0;
	while (game->c[2] < game->c[6])
	{
		if (!(ft_only(game->map[game->c[2]++], "012NSWE")))
			game->ecranx = 11;
	}
}

int			nbrjoueurtligne(t_game *game, int i)
{
	int flagpl;

	game->c[8] = 0;
	flagpl = 0;
	if (!(game->c[i] < ROWS))
		game->ecranx = 12;
	while (game->map[game->c[8]])
	{
		flagpl += ft_contient(game->map[game->c[8]], "NSWE");
		game->c[8]++;
	}
	if (flagpl == 0)
		game->ecranx = 12;
	if (!(flagpl == 1))
		game->ecranx = 12;
	return (1);
}
