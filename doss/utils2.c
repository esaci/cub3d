/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:23:43 by esaci             #+#    #+#             */
/*   Updated: 2020/12/25 16:23:49 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

int		ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int		ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

float	ft_dist(float x, float y)
{
	float res;

	res = sqrt(x*x + y*y);
	return (res);
}

void	ft_stop(t_game *game, char *log)
{
	ft_printf("Error :\n%s\n", log);
	if (game.flag[0] == 1)
		destroy_game_data(g);
	if (game.flag[0] == 2)
	{
		mlx_destroy_image(g->mlx, g->image);
		mlx_destroy_window(g->mlx, g->window);
	}
	exit(0);
	return (-1);
}
