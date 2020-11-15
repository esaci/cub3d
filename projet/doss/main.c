	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:55:18 by esaci             #+#    #+#             */
/*   Updated: 2020/11/11 17:18:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"
// Pour eviter les double faut utiliser x et y

int	main(void)
{
	t_game	game;
	t_ray	ray;
	int		time;
	int		oldtime;
	int		x;
	int		w;

    game = game_init(game);
    ray = ray_init(ray);
    var_init(&time, &oldtime, &x, &w);
	map_init(&game);
	window_init(&game);
	raycat(&game, &ray, &x, &w);.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             game, t_ray *ray, int *x, int *w)
//	step : soit +1 ou -1, direction ou aller
	mlx_loop(game.mlx.mlxptr);
	
	return (0);
}
