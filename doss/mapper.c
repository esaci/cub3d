/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:26:26 by esaci             #+#    #+#             */
/*   Updated: 2020/11/22 16:26:36 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void	map_init(t_game *game, char *pave)
{
	ft_rmap(game, pave);
	ft_rplayer(game);
}

void	ft_line(char *line, t_game *game)
{
	if (ft_strncmp(line, "R ", 3) == 0)
		ft_resolution(line + 3, game);
	if (ft_strncmp(line, "NO ", 4) == 0)
		game->img.nom[5] = (ft_strtrim(line + 4, " "));
	if (ft_strncmp(line, "SO ", 4) == 0)
		game->img.nom[7]= (ft_strtrim(line + 4, " "));
	if (ft_strncmp(line, "WE ", 4) == 0)
		game->img.nom[4] = (ft_strtrim(line + 4, " "));
	if (ft_strncmp(line, "EA ", 4) == 0)
		game->img.nom[7] = (ft_strtrim(line + 4, " "));
	if (ft_strncmp(line, "S ", 3) == 0)
		game->img.nom[3] = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "F ", 3) == 0)
		read_color(line + 3, (game->img.data[0]));
	if (ft_strncmp(line, "C ", 3) == 0)
		read_color(line + 3, (game->img.data[1]));
}


void	ft_rmap(t_game *game, char *pave)
{
	char	*line;
	game->c[0] = open(pave, O_RDONLY);
	game->c[1] = 0;
	if (game->c[0] < 0)
		ft_stop(game, "Fichier non lu");
	if (ft_strncmp(".cub", pave + ft_strlen(pave) - 4, 4) != 0 || ft_strlen(pave) <= 4)
		ft_stop(game, "Le format n'est pas valide");
	while (get_next_line(game->c[0], &line) == 1)
	{
		if (ft_only(line, "1") == 1)
			break ;
		ft_line(line,game);
		free(line);
	}
	if (!(game->map = malloc(sizeof(char *) * ROWS)))
		ft_stop(game, "Malloc probleme");
	game->map[game->c[1]++] = ft_antiespace(line, game);
	while (get_next_line(game->c[0], &line))
		gd->map[game->c[1]++] = ft_antiespace(line, game);
	game->map[game->c[1]] = '\0';
	free(line);
	if (bordurerectangle(game) && nbrjoueurtligne(game, 1))
		game->c[1] = 0;
}
