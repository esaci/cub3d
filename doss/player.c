/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:12:57 by esaci             #+#    #+#             */
/*   Updated: 2021/01/07 15:13:00 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../bibz/cub3d.h"

void	ft_rplayer(t_game *game)
{
//	game->c[0] i;
//	game->c[1] j;
//	game->c[2] b;
	game->c[2] = 1;
	while (game->c[2] == 1 && game->c[0] < game->mapy)
	{
		if (ft_contient(game->map[game->c[0]], "NSWE") >= 1)
		{
			game->c[2] = 0;
			while(ft_testc(game->map[game->c[0]][game->c[1]], "NSWE"))
				game->c[1]++;
		}
		game->c[0]++;
	}
	game->p_y = TAILLEC * game->c[0] + TAILLEC / 2;
	game->p_x = TAILLEC * game->c[1] + TAILLEC / 2;
	game->pangle = game->map[game->c[0]][game->c[1]] == 'E' ? 0 : 270;
	game->p_h = 53;
}
