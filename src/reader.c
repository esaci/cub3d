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
	if (!line[game->c[2]])
	{
		game->ecranx = 10;
		return ;
	}
	while (line[game->c[2]] == ' ')
		game->c[2]++;
	game->ecranx = ft_atoi(line + game->c[2]);
	while (ft_isdigit(line[game->c[2]]))
		game->c[2]++;
	while (line[game->c[2]] == ' ')
		game->c[2]++;
	game->ecrany = ft_atoi(line + game->c[2]);
	game->ecrany = ft_max(MIN_Y, game->ecrany);
	game->ecranx = ft_max(MIN_X, game->ecranx);
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

	if (!(res = malloc(sizeof(char) * (ft_strlen(line) + 1))))
	{
		free(line);
		game->flag[0] = -2;
		ft_stop(game, "Malloc probleme");
	}
	game->c[4] = 0;
	game->c[3] = 0;
	while (line[game->c[3]])
	{
		while (line[game->c[3]] == ' ')
			game->c[3]++;
		while (line[game->c[3]] && line[game->c[3]] != ' ')
			res[game->c[4]++] = line[game->c[3]++];
	}
	free(line);
	if (game->c[4] < 2)
	{
		game->flag[0] = -2;
		ft_stop(game, "ligne trop courte pour la map");
	}
	res[game->c[4]] = '\0';
	return (res);
}
