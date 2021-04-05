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

int	main(int argc, char **argv)
{
	t_game	game;

	game.flag[0] = -2;
	if (argc == 1)
		ft_stop(&game, "Pas de map");
	if (argc >= 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		game.flag[3] = 1;
	else
		game.flag[3] = 0;
	map_init(&game, argv[1]);
	if (argc >= 3 && ft_strncmp(argv[2], "--save", 6) == 0)
	{
		ft_bmp(&game);
		ft_stop(&game, "aucun soucis");
	}
	mlx_hook(game.mlx.win, 17, 1L << 17, &ft_windz, &game);
	mlx_key_hook(game.mlx.win, &vision, &game);
	mlx_loop_hook(game.mlx.mlxptr, &ft_depart, &game);
	mlx_loop(game.mlx.mlxptr);
	return (1);
}
