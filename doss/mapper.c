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
	game_init(game, 3);
	game->c[6] = 0;
	ft_rmap(game, pave);
	window_init(game);
	game_init(game, 1);
	ft_rplayer(game);
	game_init(game, 0);
	ft_verif(game);
	game_init(game, 0);
	ft_chargement(game);
	game_init(game, 0);
}

void	ft_line(char *line, t_game *game)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		ft_resolution(line + 2, game);
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->img.nom[4] = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "SO ", 3) == 0)
		game->img.nom[6] = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "WE ", 3) == 0)
		game->img.nom[5] = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "EA ", 3) == 0)
		game->img.nom[3] = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "S ", 2) == 0)
		game->img.nom[2] = (ft_strtrim(line + 2, " "));
	if (ft_strncmp(line, "F ", 2) == 0)
		ft_color(line + 2, (game->img.datac[0]), game);
	if (ft_strncmp(line, "C ", 2) == 0)
		ft_color(line + 2, (game->img.datac[1]), game);
}

void	ft_rmap(t_game *game, char *pave)
{
	char	*line;

	game->c[0] = open(pave, O_RDONLY);
	if (game->c[0] < 0)
		ft_stop(game, "Fichier non lu");
	if (ft_strncmp(".cub", pave + ft_strlen(pave) - 4, 4)
		!= 0 || ft_strlen(pave) <= 4)
		ft_stop(game, "Le format n'est pas valide");
	while (get_next_line(game->c[0], &line) == 1)
	{
		if (ft_only(line, " 1") == 1 && ft_strlen(line) != 0)
			break ;
		ft_line(line, game);
		free(line);
	}
	if (!(game->map = malloc(sizeof(char *) * ROWS)))
		ft_stop(game, "Malloc probleme");
	game->map[0] = ft_antiespace(line, game);
	game->c[1] = 1;
	while (get_next_line(game->c[0], &line))
		game->map[game->c[1]++] = ft_antiespace(line, game);
	game->map[game->c[1]] = '\0';
	free(line);
	bordurerectangle(game);
	nbrjoueurtligne(game, 1);
}
