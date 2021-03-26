/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chargement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:52:50 by esaci             #+#    #+#             */
/*   Updated: 2021/01/07 16:52:55 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void		ft_verif(t_game *game)
{
	game->c[2] = open(game->img.nom[2], O_RDONLY);
	game->c[3] = open(game->img.nom[3], O_RDONLY);
	game->c[4] = open(game->img.nom[4], O_RDONLY);
	game->c[5] = open(game->img.nom[5], O_RDONLY);
	game->c[6] = open(game->img.nom[6], O_RDONLY);
	game->flag[0] = 1;
	if (game->c[2] < 0 || game->c[3] < 0 || game->c[4] < 0
		|| game->c[5] < 0 || game->c[6] < 0)
		ft_stop(game, "Pas pu charger NSEW ou le sprite");
}

void		ft_chargement(t_game *game)
{
	int		i;

	i = 2;
	while (i <= 6)
	{
		initxpmptr(game, i, game->img.nom[i]);
		i++;
	}
}
