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

int	main(void)
{
	t_game	game;
	t_ray	ray;

	game = game_init(game);
	ray = ray_init(ray);
	var_init(&game);
	map_init(&game);
	window_init(&game);
	mlx_key_hook (game.mlx.win, &vision, &game);
	mlx_loop_hook(game.mlx.mlxptr, &setuped, &game);
	mlx_loop(game.mlx.mlxptr);
	return (0);
}