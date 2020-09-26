/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:55:18 by esaci             #+#    #+#             */
/*   Updated: 2020/09/26 21:47:02 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// Pour eviter les double faut utiliser x et y
void	window_init(t_game *game)
{
	game->mlx.mlxptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlxptr, screenWIDTH, screenHEIGHT, "fenetre init");
	game->img.imgptr = mlx_xpm_file_to_image(game->mlx.mlxptr, "wtf.xpm", screenWIDTH / 10, screenHEIGHT / 10);
	mlx_put_image_to_window(game->mlx.mlxptr, game->win., game->img.imgptr, screenWIDTH / 10, screenHEIGHT / 10);
}

int		eliasabs(float x)
{
	if (x < 0)
		x = -x;
	return (x);
}

void	map_init(t_game *game)
{
	int	map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

int	touche_appuye(int keycode, int *j)
{
	if (keycode == KEY_W)
		*j = *j + 1;
	else if(keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	main(void)
{
	t_game	game;
	t_ray	ray;
	int		time;
	int		oldtime;
	int		x;
	int		w;

	game.vise = 0;
	game.dx = 1;
	game.dy = 2;
	time = 0;
	oldtime = 0;
	ray.px = 0;
	ray.py = 0.66;
	game.posx = 22;
	game.posy = 12;
	map_init(&game);
	window_init(&game);
	w = screenWIDTH;
	x = 0;
// calcul pour chaque ligne verticale, ca commence a la (ray.px, ray.py)
// cameraX est la projection de ray.px sur le plan, avec ce calcul tout a gauche -1, milieu 0 et a droite a gauche
// 
	while (x < w)
	{
		game.cameraX = 2 * x / w - 1;
		ray.rayDirx = game.dx + ray.px * game.cameraX;
		ray.rayDiry = game.dy + ray.py * game.cameraX;
		x++;
	}
// mapX et et mapY rpz le carre ou est lobjet quon ray c donc entier
// sideDistX et sideDistY distance entre lobjet et le premiere entier x ou entier y
// deltaDistX et deltaDistY c d'un entier x et y a l'autre entier
	game.mapX = (int)(game.posx);
	game.mapY = (int)(game.posy);
	ray.deltaDistX = eliasabs(1 / ray.rayDirx);
	ray.deltaDistY = eliasabs(1 / ray.rayDiry);
//	step : soit +1 ou -1, direction ou aller
	mlx_loop(game.mlx.mlxptr);
	game.hit = 0;

	if (ray.rayDirx < 0)
	{
		game.step = -1;
		ray.sideDistX = (game.posx - game.mapX) * ray.deltaDistX;
	}
	else
	{
		game.stepX = 1;
		ray.sideDistX = (game.mapX + 1 - game.posx) * ray.deltaDistX;
	}
	if (ray.rayDiry < 0)
	{
		game.step = -1;
		ray.sideDistY = (game.posy - game.mapY) * ray.deltaDistY;
	}
	else
	{
		game.stepY = 1;
		ray.sideDistY = (game.mapY + 1 - game.posy) * ray.deltaDistY;
	}
// tant qu'n a rien tape, on avance, si on tape tout stop et side vaut 0 si on bouge en X sinon 1 et bouge en Y
	while (game.hit == 0)
	{
		if (ray.sideDistX < ray.sideDistY)
		{
			ray.sideDistX += ray.deltaDistX;
			game.mapX += game.stepX;
			game.side = 0;
		}
		else {
			ray.sideDistY += ray.deltaDistY;
			game.mapY += game.stepY;
			game.side = 1;
		}
		if (game.map[game.mapX][game.mapY] > 0)
			game.hit = 1;
	}
// perpWallDist taille de la ligne perpendiculaire a mon plan de camera et touche H, le point qui est raycast, MTN DIFF X ET Y ?
	if(game.side == 0)
		ray.perpWallDist = (game.mapX - game.posx + (1 - game.stepX) / 2) / ray.rayDirx;
	else
		ray.perpWallDist = (game.mapY - game.posy + (1 - game.stepY) / 2) / ray.rayDiry;
// taille de la ligne direct entre la pos et le point qui est raycast
	ray.lineHeight = (int)(game.vise / ray.perpWallDist);
	ray.drawstart = -ray.lineHeight / 2 + game.vise / 2;
	if (ray.drawstart < 0)
		ray.drawstart = 0;
	ray.drawend = ray.lineHeight / 2 + game.vise / 2;
	if (ray.drawend < 0)
		ray.drawend = game.vise - 1;
	return (0);
}
