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
	game->img.imgptr[0] = mlx_new_image(game->mlx.mlxptr, SCREENWIDTH, SCREENHEIGHT);
	game->img.data[0] = (int*)mlx_get_data_addr(game->img.imgptr[0], &game->img.bpp[0], &game->img.size_l[0], &game->img.endian[0]);
	game->img.imgptr[1] = mlx_xpm_file_to_image(game->mlx.mlxptr, "./doss/image/wtf.XPM", &game->img.width[1], &game->img.height[1]);
	game->img.data[1] = (int*)mlx_get_data_addr(game->img.imgptr[1], &game->img.bpp[1], &game->img.size_l[1], &game->img.endian[1]);
	game->img.imgptr[2] = mlx_xpm_file_to_image(game->mlx.mlxptr, "./doss/image/vroom.xpm", &game->img.width[2], &game->img.height[2]);
	game->img.data[2] = (int*)mlx_get_data_addr(game->img.imgptr[2], &game->img.bpp[2], &game->img.size_l[2], &game->img.endian[2]);
}

void	effiche(t_game *game, int i)
{
	if (i < 0)
	{
		i = -i;
		mlx_destroy_image(game->mlx.mlxptr, game->img.imgptr[3]);
	}
	game->img.width[3] = game->img.width[i];
	game->img.height[3] = game->img.height[i];
	game->img.dx[3] = game->img.dx[i];
	game->img.dy[3] = game->img.dy[i];
	game->img.imgptr[3] = mlx_new_image(game->mlx.mlxptr, game->img.width[3], game->img.height[3]);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[3], game->img.dx[3], game->img.dy[3]);
}

int	vision(int	keycode, void *ptr)
{
	t_game	*game;

	game = (t_game*)ptr;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_Z)
	{
		exit(0);
	}
	else if (keycode == KEY_Q)
	{
		game->img.dx[1] = SCREENWIDTH / game->hit;
		game->img.dy[1] = SCREENHEIGHT / game->hit ;
		game->hit++;
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[1], game->img.dx[1], game->img.dy[1]);
	}
	else if (keycode == KEY_S)
	{
		game->img.dx[0] = 0;
		game->img.dy[0] = 0;
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[0], game->img.dx[0] , game->img.dy[0]);
		game->hit = 2;
		game->step = 1;
	}
	else if (keycode == KEY_D)
	{
		if (game->step >= 4)
			effiche(game, -2);
		if (game->step == 2)
			effiche(game, 2);
		game->img.dx[2] = game->step;
		game->img.dy[2] = game->step;
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[2], game->img.dx[2] , game->img.dy[2]);
		game->step = game->step * 2;
	}
	return(0);
}
