/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:55:18 by esaci             #+#    #+#             */
/*   Updated: 2020/09/20 00:54:27 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
	
int	main(void)
{
	t_game	game;
	t_ray	ray;
	int		time;
	int		oldtime;
	int		x;
	int		w;


	game.dx = 5;
	game.dy = 6;
	time = 0;
	oldtime = 0;
	ray.px = 3;
	ray.py = 2;
	game.posx = 3;
	game.posy = 2;
	map_init(&game);
	window_init(&game);
	img_init(&game);
	ft_ecran(screenWIDTH, screenHEIGHT 0, "raycaster");
	w = screenWIDTH;
	x = 0;
// calcul pour chaque ligne verticale, ca commence a la (ray.px, ray.py)
// cameraX est la projection de ray.px sur le plan, avec ce calcul tout a gauche -1, milieu 0 et a droite a gauche
// 
	while (x < w)
	{
		game.cameraX = 2 * x / w - 1;
		game.rayDirx = game.dx + ray.px * ray.cameraX;
		game.rayDiry = game.dy + ray.py * ray.cameraX;
		x++;
	}
// mapX et et mapY rpz le carre ou est lobjet quon ray c donc entier
// sideDistX et sideDistY distance entre lobjet et le premiere entier x ou entier y
// deltaDistX et deltaDistY c d'un entier x et y a l'autre entier
	game.mapX = int(game.posx);
	game.mapY = int(game.posy);

	mlx_loop(game.mlx.mlxptr);
	return (0);
}
