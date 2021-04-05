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

	res = x * x + y * y;
	res = sqrt(res);
	return (res);
}

void	ft_stop(t_game *game, char *error)
{
	int		i;

	if (game->flag[0] == -2)
	{
		printf("Error :\n%s\n", error);
		exit(0);
	}
	if (ft_strncmp(error, "Map", 3) == 0)
	{
		destroyernom(game, "Pas pu charger la", 2);
		printf("Error :\n%s\n", error);
		exit(0);
	}
	i = (game->flag[3] == 1) ? 6 : 5;
	if (game->flag[0] >= 2)
		destroyer(*game, i, 2, 3, 4, 5, 6, 7);
	if (game->flag[0] >= 1)
		destroyernom(game, error, 2);
	if (ft_strncmp(error, "aucun soucis", 9) == 0)
		exit(0);
	printf("Error :\n%s\n", error);
	exit(0);
}
