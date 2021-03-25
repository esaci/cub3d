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

void	swapbmp(t_game *game, char *str)
{
	int		j;
	char	*str2;
	char	*str3;
	int		i;

	if (!(str2 = malloc(sizeof(char) * 4 + 1)))
		ft_stop(game, "mallox str2 bloqué");
	j = 0;
	str3 = str + 54;
	while (j < game->ecrany / 2)
	{
		i = 0;
		while (i < game->ecranx * 4)
		{
			while(!(str3[game->ecranx * j * 4 + i]) || !(str3[game->ecranx * (game->ecrany - j) * 4 + i]))
				i++;
			*(str2) = str3[game->ecranx * j * 4 + i];
			str3[game->ecranx * j * 4 + i] =
				str3[game->ecranx * (game->ecrany - j) * 4 + i];
			str3[game->ecranx * (game->ecrany - j) * 4 + i] = *(str2);
			i++;
		}
		j++;
	}
	free(str2);
}

void	headbmp2(t_game *game, char *str, int i)
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
}

void	headbmp(t_game *game, char *str, int np)
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
	headbmp2(game, str, i);
}
