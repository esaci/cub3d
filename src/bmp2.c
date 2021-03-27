/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:38:50 by esaci             #+#    #+#             */
/*   Updated: 2021/03/14 15:39:02 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void	swapbmp(t_game *game, char *str3, int j, char *str2)
{
	int		i;

	while (j < (int)(game->ecrany / 2))
	{
		i = 0;
		while ((!(str3[game->ecranx * j * 4 + i]) || !(str3[game->ecranx
			* (game->ecrany - j) * 4 + i])) && i < game->ecranx * 4)
			i++;
		while (i < game->ecranx * 4)
		{
			*(str2) = str3[game->ecranx * j * 4 + i];
			str3[game->ecranx * j * 4 + i] =
				str3[game->ecranx * (game->ecrany - j) * 4 + i];
			str3[game->ecranx * (game->ecrany - j) * 4 + i] = *(str2);
			i++;
			while ((!(str3[game->ecranx * j * 4 + i]) || !(str3[game->ecranx
				* (game->ecrany - j) * 4 + i])) && i < game->ecranx * 4)
				i++;
		}
		j++;
	}
	free(str2);
}

int		headbmp2(t_game *game, char *str, int i)
{
	divid(str, &i, 0);
	divid(str, &i, game->ecranx * game->ecrany);
	str[i++] = 0x13;
	str[i++] = 0x0b;
	str[i++] = 0;
	str[i++] = 0;
	str[i++] = 0x13;
	str[i++] = 0x0b;
	str[i++] = 0;
	str[i++] = 0;
	divid(str, &i, 0);
	divid(str, &i, 0);
	return (i);
}

int		headbmp(t_game *game, char *str, int np)
{
	int		i;

	i = 0;
	str[i++] = 'B';
	str[i++] = 'M';
	np = np + 54;
	divid(str, &i, np);
	divid(str, &i, 0);
	str[i++] = 54;
	divid(str, &i, 0);
	i = i - 1;
	str[i++] = 40;
	divid(str, &i, 0);
	i = i - 1;
	divid(str, &i, game->ecranx);
	divid(str, &i, game->ecrany);
	str[i++] = 1;
	str[i++] = 0;
	str[i++] = 32;
	str[i++] = 0;
	i = headbmp2(game, str, i);
	return (i);
}
