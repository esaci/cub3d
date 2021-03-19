/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:57:36 by esaci             #+#    #+#             */
/*   Updated: 2020/11/27 15:57:38 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

void	initmlxptr(t_game *game, int i, int width, int height)
{
	game->img.imgptr[i] = mlx_new_image(game->mlx.mlxptr, width, height);
	mlx_get_data_addr(game->img.imgptr[i], &game->img.bpp[i], &game->img.size_l[i], &game->img.endian[i]);
}

void	initxpmptr(t_game *game, int i, char *str)
{
	game->img.imgptr[i] = mlx_xpm_file_to_image(game->mlx.mlxptr, str, &game->img.width[i], &game->img.height[i]);
	game->img.data[i] = mlx_get_data_addr(game->img.imgptr[i], &game->img.bpp[i], &game->img.size_l[i], &game->img.endian[i]);
}

void	drawpix(t_game *game, t_pix pix, unsigned char couleur[4])
{
	ft_memcpy(game->img.data[7] + 4 * game->ecranx * pix.y + pix.x * 4, couleur, sizeof(int));
}

void			copypix(t_game *game, t_pix *pix)
{
	float			dist;
	unsigned char	shade[4];

	dist = fabs(game->ray.dist[1] * cos((game->ray.angle[1] - (float)game->pangle * 0.0174f)));
	if (dist == 0)
		dist = 2;
	pix->y--;
	if (!(pix->x < game->ecranx && pix->y < game->ecrany))
		return ;
	game->c[8] = 0;
	while (game->c[8] < 3)
	{
		shade[game->c[8]] = (unsigned char)(game->img.data[2][game->c[8]]);
		game->c[8]++;
	}
	shade[4] = 0;
	ft_memcpy(game->img.data[7] + 4 * game->ecranx * pix->y + pix->x * 4,
			&(shade), sizeof(int));
	pix->y++;
}

void		drawrectimg(t_game	*game, int i, int ry)
{
	float		dist;
	int			height;
	t_pix		pix;

	dist = fabs(game->ray.dist[1] * cos((game->ray.angle[1] - (float)game->pangle * 0.0174f)));
	if (dist == 0)
		dist = 2;
	height = ceil(game->ecrany / dist);
	pix.x = i;
	pix.flag = game->ray.x[ry];
	pix.y = 0;
	while (pix.y < (game->ecrany - height) / 2)
	{
		drawpix(game, pix, game->img.datac[0]);
		pix.y++;
	}
	while (pix.y < (game->ecrany + height) / 2 && pix.y++ < game->ecrany)
		copypix(game, &pix);
	while (pix.y < (game->ecrany))
	{
		drawpix(game, pix, game->img.datac[1]);
		pix.y++;
	}
}
