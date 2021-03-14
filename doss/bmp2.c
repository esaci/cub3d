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
/* str2 stock la premiere ligne,  */

	if (!(str2 = malloc(sizeof(char) * game->ecranx * 3 + 1)))
		ft_stop(game, "mallox str2 bloqué");
	j = 0;
	str3 = str + 54;
	while (j < game->ecrany / 2)
	{
		i = 0;
		while (i < game->ecranx * 4)
		{
			str2[i] = str3[game->ecranx * j * 4 + i];
			str3[game->ecranx * j * 4 + i] = str3[game->ecranx * (game->ecrany - j) * 4 + i];
			str3[game->ecranx * (game->ecrany - j) * 4 + i] = str2[i];
			i++;
		}
		/* ft_memcpy(str2, str3 + game->ecranx * j * 3, game->ecranx * 3); */
/* 		ft_printf("%s _ %d vs %d \n", str2, j, game->ecrany - j);
		ft_memcpy(str3 + game->ecranx * j * 3, str3 + game->ecranx * (game->ecrany - j) * 3 , game->ecranx * 3);
		ft_memcpy(str3 + game->ecranx * (game->ecrany - j) * 3 , str2, game->ecranx * 3); */
		j++;
	}
	free(str2);
}

void	headbmp2(t_game *game, char *str, int i)
{
	/* compression method  i = 30*/
	divid(str, &i, 0);
	/* Image size 34*/
	divid(str, &i, game->ecranx * game->ecrany);
	/* Pixels per meter in X axis i = 38*/
	str[i++] = 0x13;
	str[i++] = 0x0b;
	str[i++] = 0;
	str[i++] = 0;
	/* Pixels per meter in Y axis i = 42*/
	str[i++] = 0x13;
	str[i++] = 0x0b;
	str[i++] = 0;
	str[i++] = 0;
	/* i = 46; */
	/* Colors used */
	divid(str, &i, 0);
	/* Important colors */
	divid(str, &i, 0);
}

void	headbmp(t_game *game, char *str, int np)
{
	int		i;

	i = 0;
	str[i++] = 'B';
	str[i++] = 'M';
	/* i = 2 */
	np = np + 54;
	divid(str, &i, np);
	/* i = 6 */
	divid(str, &i, 0);
	/* i = 9 */
	/* Data offset */
	str[i++] = 54;
	/* i = 10 4 bits pour le dataoffset donc le reste c unused */
	divid(str, &i, 0);
	i = i -1;
	/* Size of the header : 40 i = 14*/
	str[i++] = 40;
	divid(str, &i, 0);
	i = i -1;
	/* Width */
	divid(str, &i, game->ecranx);
	/* Height */
	divid(str, &i, game->ecrany);
	/* Planes  2bytes */
	str[i++] = 1;
	str[i++] = 0;
	/* bits per pixel  2 bytes*/
	str[i++] = 32;
	str[i++] = 0;
 	headbmp2(game, str, i);
}
