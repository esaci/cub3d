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

int			ft_testdep(t_game *game, int mapc,
			int key2, void (*fct)(t_game*, int, int, int))
{
	if (mapc != '1' && mapc != '2' && key2 != 'E')
		fct(game, key2, 'E', 10);
	else
		return (1);
	return (0);
}

void		deplacement(t_game *game, int key, int key2, int flag)
{
	int		count1;
	int		count2;
	char	mapc;

	if (key2 == 'E')
		flag = 3;
	count1 = game->posx;
	count2 = game->posy;
	if (key == KEY_Z)
	{
		count1 += (12 + flag) * cos(game->pangle * 0.0174);
		count2 += (12 + flag) * -sin(game->pangle * 0.0174);
		mapc = game->map[count2 / 64][count1 / 64];
	}
	if (key == KEY_S)
	{
		count1 -= (12 + flag) * cos(game->pangle * 0.0174f);
		count2 -= (12 + flag) * -sin(game->pangle * 0.0174f);
		mapc = game->map[count2 / 64][count1 / 64];
	}
	if (ft_testdep(game, mapc, key2, &deplacement))
		return ;
	game->posx = count1;
	game->posy = count2;
}

void		deplacement2(t_game *game, int key, int key2, int flag)
{
	int		count1;
	int		count2;
	char	mapc;

	if (key2 == 'E')
		flag = 3;
	count1 = game->posx;
	count2 = game->posy;
	if (key == KEY_Q)
	{
		count2 -= (12 + flag) * cos(game->pangle * 0.0174f);
		count1 += (12 + flag) * -sin(game->pangle * 0.0174f);
		mapc = game->map[count2 / 64][count1 / 64];
	}
	if (key == KEY_D)
	{
		count2 += (12 + flag) * cos(game->pangle * 0.0174f);
		count1 -= (12 + flag) * -sin(game->pangle * 0.0174f);
		mapc = game->map[count2 / 64][count1 / 64];
	}
	if (ft_testdep(game, mapc, key2, &deplacement2))
		return ;
	game->posx = count1;
	game->posy = count2;
}

int			vision(int keycode, t_game *game)
{
	int		test;

	test = 0;
	if (keycode == KEY_ESC)
		ft_stop(game, "aucun soucis");
	else if (keycode == KEY_LEFT)
		test += 10;
	else if (keycode == KEY_RIGHT)
		test -= 10;
	else if (keycode == KEY_S)
		deplacement(game, KEY_S, 0, 10);
	else if (keycode == KEY_Z)
		deplacement(game, KEY_Z, 0, 10);
	if (keycode == KEY_Q)
		deplacement2(game, KEY_Q, 0, 10);
	else if (keycode == KEY_D)
		deplacement2(game, KEY_D, 0, 10);
	game->pangle += test;
	game->pangle = game->pangle % 360;
	return (0);
}
