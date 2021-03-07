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


void	ft_elias(t_game *game)
{
	int i;
	int j;

	i = 0;
	ft_printf("\n");
	while (game->map[i] && game->map[i][0] != '\n')
	{
		if (i == (int)(game->posy / 64))
		{
			j = 0;
			while(game->map[i][j])
			{
				if (j == game->posx / 64)
					ft_printf("X");
				else
					ft_printf("%c", game->map[i][j]);
				j++;
			}
			printf("\n");
		}
		else
			ft_printf("%s -\n", game->map[i]);
		i++;
	}
}

void		deplacement(t_game *game, int key, int key2)
{
	int		count1;
	int		count2;
	char	mapc;
	int 	flag;

	flag = 20;
	if (key2 == 'E')
		flag = 10;
	count1 = game->posx;
	count2 = game->posy;
	if (key == KEY_Z)
	{
		count1 += (12 + flag) * cos(game->pangle * 0.0174);
		count2 += (12 + flag) * -sin(game->pangle * 0.0174);
		mapc = game->map[count2 / 64][count1 / 64];
		if (mapc != '1' && mapc != '2' && key2 != 'E')
			deplacement(game, key, 'E');
		else
			return ;

	}
	if (key == KEY_S)
	{
		count1 -= (12 + flag) * cos(game->pangle * 0.0174f);
		count2 -= (12 + flag) * -sin(game->pangle * 0.0174f);
		mapc = game->map[count2 / 64][count1 / 64];
		if (mapc != '1' && mapc != '2' && key2 != 'E')
			deplacement(game, key, 'E');
		else
			return ;
	}
	game->posx = count1;
	game->posy = count2;
	return ;
}

void		deplacement2(t_game *game, int key, int key2)
{
	int		count1;
	int		count2;
	char	mapc;
	int 	flag;

	flag = 10;
	if (key2 == 'E')
		flag = 5;
	count1 = game->posx;
	count2 = game->posy;
	if (key == KEY_Q)
	{
		count2 -= (12 +flag) * cos(game->pangle * 0.0174f);
		count1 += (12 +flag) * -sin(game->pangle * 0.0174f);
		mapc = game->map[count2 / 64][count1 / 64];
		if (mapc != '1' && mapc != '2' && key2 != 'E')
			deplacement2(game, key, 'E');
		else
			return ;
	}
	if (key == KEY_D)
	{
		count2 += (12 +flag) * cos(game->pangle * 0.0174f);
		count1 -= (12 +flag) * -sin(game->pangle * 0.0174f);
		mapc = game->map[count2 / 64][count1 / 64];
		if (mapc != '1' && mapc != '2' && key2 != 'E')
			deplacement2(game, key, 'E');
		else
			return ;
	}
//	ft_printf("depl x : %d , depl y : %d \n", game->posx - count1, game->posy - count2);
	game->posx = count1;
	game->posy = count2;
}

int	vision(int	keycode, t_game *game)
{
	int	test;

	test = 0;
	ft_printf("Emplacement : %d / %d  - %d°\n", game->posx / 64, game->posy / 64, game->pangle);
//	ft_printf("Emplacement : %d / %d  - %d°\n", game->posx / 64, game->posy / 64, game->pangle);
	if (keycode == KEY_ESC)
	{
		ft_stop(game, "echap");
	}
	else if (keycode == KEY_LEFT)
	{
		test += 10;
		game->flag[2] = 1;
	}
	else if (keycode == KEY_RIGHT)
	{
		test -= 10;
		game->flag[2] = 1;
	}
	else if (keycode == KEY_S)
	{
		deplacement(game, KEY_S, 0);
		game->flag[2] = 1;
	}
	else if (keycode == KEY_Z)
	{
		deplacement(game, KEY_Z, 0);
		game->flag[2] = 1;
	}
	if (keycode == KEY_Q)
	{
		deplacement2(game, KEY_Q, 0);
		game->flag[2] = 1;
	}
	else if (keycode == KEY_D)
	{
		deplacement2(game, KEY_D, 0);
		game->flag[2] = 1;
	}
	game->pangle += test;
	game->pangle = game->pangle % 360;
//	ft_printf("%d [0], %d [1] \n", game->ray.y[0], game->ray.y[1]);
//	ft_printf("x %d / y  %d\n",(game->ray.y[0] + ft_signe(game->ray.y[0] - game->posy)) / 64, (game->ray.x[0] + ft_signe(game->ray.x[0] - game->posx)) / 64);
//	ft_printf("x %d / y  %d\n",(game->ray.y[1] + ft_signe(game->ray.y[1] - game->posy)) / 64, (game->ray.x[1] + ft_signe(game->ray.x[1] - game->posx)) / 64);
	return(0);
}
