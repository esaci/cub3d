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
	game_init(game, 0);
	ft_rplayer(game);
	ft_verif(game);
	ft_chargement(game);
	affichemap(game);
}

void	ft_line(char *line, t_game *game)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		ft_resolution(line + 2, game);
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->img.nom[4] = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "SO ", 3) == 0)
		game->img.nom[6]= (ft_strtrim(line + 3, " "));
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
	if (ft_strncmp(".cub", pave + ft_strlen(pave) - 4, 4) != 0 || ft_strlen(pave) <= 4)
		ft_stop(game, "Le format n'est pas valide");
	while (get_next_line(game->c[0], &line) == 1)
	{
		if (ft_only(line, " 1") == 1 && ft_strlen(line) != 0)
			break;
		ft_line(line,game);
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
	if (bordurerectangle(game) && nbrjoueurtligne(game, 1))
		game->c[1] = 0;
}

void		affichemap(t_game *game)
{
	int i;

	ft_printf("R  %d * %d\n", game->ecranx, game->ecrany);
	ft_printf("NO  %s\n", game->img.nom[4]);
	ft_printf("SO  %s\n", game->img.nom[6]);
	ft_printf("WE  %s\n", game->img.nom[5]);
	ft_printf("EA  %s\n", game->img.nom[3]);
	ft_printf("S  %s\n", game->img.nom[2]);
	ft_printf("F  %d,", (game->img.datac[0][0]));
	ft_printf("%d,", (game->img.datac[0][1]));
	ft_printf("%d\n", (game->img.datac[0][2]));
	ft_printf("C  %d,", (game->img.datac[1][0]));
	ft_printf("%d,", (game->img.datac[1][1]));
	ft_printf("%d\n", (game->img.datac[1][2]));
	i = 0;
	while (game->map[i] && game->map[i][0] != '\n')
	{
		ft_printf("%s - %d\n", game->map[i], i);
		i++;
	}
	ft_printf("Taille map = %d * %d\n", game->mapx, game->mapy);
}
