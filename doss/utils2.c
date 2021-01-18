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

void	ft_stop(t_game *game, char *error)
{
	ft_printf("Error :\n%s\n", error);
	if (game->flag[0] == 1)
		ft_printf("flag 1\n");
	if (game->flag[0] == 2)
	{
		destroyer(*game, 4, 2, 3, 4, 5);
	}
	exit(0);
}
