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

void	window_init(t_game *game)
{
	game->mlx.mlxptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlxptr, SCREENWIDTH, SCREENHEIGHT, "fenetre init");
	initmlxptr(game, 10, SCREENWIDTH, SCREENHEIGHT);
	initxpmptr(game, 1, "./doss/image/wtf.XPM");
	initxpmptr(game, 2, "./doss/image/vroom.xpm");
	modifdxdy(game, 1, SCREENWIDTH / game->hit, SCREENHEIGHT / game->hit);
}

void	effiche(t_game *game, int i)
{
	if (i < 0)
	{
		game->flag = 1;
		i = -i;
		mlx_destroy_image(game->mlx.mlxptr, game->img.imgptr[3]);
	}
	modifdxdy(game, 3, game->img.dx[i], game->img.dy[i]);
	modifhw(game, 3, game->img.height[i], game->img.width[i]);
	initmlxptr(game, 3, game->img.width[3], game->img.height[3]);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[3], game->img.dx[3], game->img.dy[3]);
}

void	divim(t_game *game, int i)
{
	game->img.width[4] = game->img.width[i];
	game->img.height[4] = game->img.height[i];
	game->img.dx[4] = game->img.dx[i];
	game->img.dy[4] = game->img.dy[i];
	game->img.imgptr[4] = mlx_new_image(game->mlx.mlxptr, game->img.width[i] / 10, game->img.height[i] / 10);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[i], game->img.dx[i], game->img.dy[i]);
}

int	vision(int	keycode, void *ptr)
{
	t_game	*game;

	game = (t_game*)ptr;
	if (keycode == KEY_ESC)
	{
		destroyer(*game, 3, 10, 1, 2);
		if(game->flag == 1)
			destroyer(*game, 1, 3);
		exit(0);
	}
	else if (keycode == KEY_Z)
	{
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[10], 0, 0);
		drawrectimg(game, 5, 1, game->img.height[1] * (5/4), game->img.width[1] * (5/4), game->img.dx[1], game->img.dy[1]);
	}
	else if (keycode == KEY_Q)
	{
		modifdxdy(game, 1, SCREENWIDTH / game->hit, SCREENHEIGHT / game->hit);
		drawrectimg(game, 5, 1, game->img.height[1] , game->img.width[1], game->img.dx[1], game->img.dy[1]);
		game->hit++;
	}
	else if (keycode == KEY_S)
	{
		drawrectimg(game, 5, 1, game->img.height[1] / 2, game->img.width[1] / 2, game->img.dx[1], game->img.dy[1]);
	}
	else if (keycode == KEY_D)
	{
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[10], 0, 0);
		modifdxdy(game, 1, game->img.dx[1] * 2, game->img.dy[1] * 2);
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[1], game->img.dx[1] , game->img.dy[1]);
	}
	return(0);
}
