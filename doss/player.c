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

int		ft_angle(char c)
{
	int angle;

	angle = 0;
	if (c == 'N')
		angle = 90;
	if (c == 'W')
		angle = 180;
	if (c == 'S')
		angle = 270;
	return (angle);
}

void	ft_rplayer(t_game *game)
{
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
	game->pangle = ft_angle(game->map[game->c[0]][game->c[1]]);
	game->posy = TAILLEC * game->c[0] + TAILLEC / 2;
	game->posx = TAILLEC * game->c[1] + TAILLEC / 2;
}
