/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:00:41 by esaci             #+#    #+#             */
/*   Updated: 2020/11/22 16:03:03 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void		deplacement(t_game *game, int key, int key2)
{
	int		count1;
	int		count2;
	char	mapc;
	int 	flag;

	flag = 0;
	if (key2 == 'E')
		flag = 5;
	count1 = game->posx;
	count2 = game->posy;
	if (key == KEY_Z)
	{
		count1 += (10 + flag) * cos(game->pangle * 0.0174f);
		count2 += (10 + flag) * -sin(game->pangle * 0.0174f);
		mapc = game->map[count2 / 64][count1 / 64];
		if (mapc != '1' && mapc != '2' && key2 != 'E')
			deplacement(game, key, 'E');
	}
	if (key == KEY_S)
	{
		count1 -= (10 + flag) * cos(game->pangle * 0.0174f);
		count2 -= (10 + flag) * -sin(game->pangle * 0.0174f);
		mapc = game->map[count2 / 64][count1 / 64];
		if (mapc != '1' && mapc != '2' && key2 != 'E')
			deplacement(game, key, 'E');
	}
	game->posx = count1;
	game->posy = count2;
	return ;
}

int	vision(int	keycode, t_game *game)
{
	int	test;

	test = 0;
	if (keycode == KEY_ESC)
	{
		ft_stop(game, "echap");
	}
	else if (keycode == KEY_Z)
	{
		deplacement(game, KEY_Z, 0);
	}
	else if (keycode == KEY_Q)
	{
		test += 10;
	}
	else if (keycode == KEY_S)
	{
		deplacement(game, KEY_S, 0);
	}
	else if (keycode == KEY_D)
	{
		test -= 10;
	}
	test = test % 360;
	game->pangle += test;
	ft_printf("%d / %d  - %d°\n", game->posx / 64, game->posy / 64, game->pangle);
	return(0);
}
