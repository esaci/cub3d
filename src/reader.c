/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:58:40 by esaci             #+#    #+#             */
/*   Updated: 2021/01/06 16:58:58 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void	ft_resolution(char *line, t_game *game)
{
	game->c[2] = 0;
	while (line[game->c[2]] == ' ')
		game->c[2]++;
	game->ecranx = ft_atoi(line + game->c[2]);
	game->ecranx = ft_max(MIN_X, game->ecranx);
	game->ecranx = ft_min(MAX_X, game->ecranx);
	while (ft_isdigit(line[game->c[2]]))
		game->c[2]++;
	while (line[game->c[2]] == ' ')
		game->c[2]++;
	game->ecrany = ft_atoi(line + game->c[2]);
	game->ecrany = ft_max(MIN_Y, game->ecrany);
	game->ecrany = ft_min(MAX_Y, game->ecrany);
}

void	ft_color(char *line, unsigned char *datac, t_game *game)
{
	game->c[2] = 0;
	while (line[game->c[2]] == ' ')
		game->c[2]++;
	datac[0] = (unsigned char)ft_atoi(line + game->c[2]);
	while (ft_isdigit(line[game->c[2]]))
		game->c[2]++;
	while (line[game->c[2]] == ' ' || line[game->c[2]] == ',')
		game->c[2]++;
	datac[1] = (unsigned char)ft_atoi(line + game->c[2]);
	while (ft_isdigit(line[game->c[2]]))
		game->c[2]++;
	while (line[game->c[2]] == ' ' || line[game->c[2]] == ',')
		game->c[2]++;
	datac[2] = (unsigned char)ft_atoi(line + game->c[2]);
	datac[3] = '\0';
	game->c[2] = 0;
}

char	*ft_antiespace(char *line, t_game *game)
{
	char *res;
	char *str;

	str = line;
	game->c[4] = 0;
	game->c[3] = 0;
	if (!(res = malloc(sizeof(char) * ft_strlen(line))))
		ft_stop(game, "Malloc probleme");
	while (line[game->c[3]])
	{
		while (line[game->c[3]] == ' ')
			game->c[3]++;
		while (line[game->c[3]] && line[game->c[3]] != ' ')
			res[game->c[4]++] = line[game->c[3]++];
	}
	res[game->c[4]] = '\0';
	free(str);
	return (res);
}
