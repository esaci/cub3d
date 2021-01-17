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
	game->img.data[i] = mlx_get_data_addr(game->img.imgptr[i], &game->img.bpp[i], &game->img.size_l[i], &game->img.endian[i]);
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

void	drawsprite(t_game *game, t_pix *pix, int height)
{
	int		countp;
	unsigned char	color[3];

	if (pix->x >= game->ecranx || pix->y >= game->ecrany)
		return ;
	countp = (pix->y - (game->ecrany - height) / 2) * 64 / height;
	countp = (pix->flag % 64) * 4 + (countp % 64) * game->img.size_l[2];
//	countp = pix->y  * game->img.size_l[2] + height * 0;
	countp = ft_max(0, countp);
	game->c[8] = 0;
	while (game->c[8] < 3)
	{
		color[game->c[8]] = (unsigned char)game->img.data[2][countp + game->c[8]];
		game->c[8]++;
	}
	ft_memcpy(game->img.data[7] + 4 * game->ecranx * pix->y + pix->x * 4, color, sizeof(int));
}

void		drawrectimg(t_game	*game, int i, int ry)
{
	float			dist;
	int				height;
	t_pix			pix;

	dist = fabs(game->ray.dist[ry] * cos((game->ray.angle[ry] - (float)game->pangle * 0.0174f)));
	if (dist <= 1)
		dist = 1;
//	ft_stop(game, ft_itoa(game->ray.dist[1]));
	height = ceil(128 * (game->ecrany / dist));
	pix.x = i;
	pix.flag = game->ray.x[ry];
	pix.y = 0;
	while (pix.y++ < (game->ecrany - height) / 2)
		drawpix(game, pix, game->img.datac[0]);
	game->c[9] = 0;
	while (pix.y < (game->ecrany + height) / 2 && pix.y < game->ecrany)
	{
//		ft_stop(game,"etape");
		drawsprite(game, &pix, height);
		pix.y++;
	}
	while (pix.y++ < (game->ecrany))
		drawpix(game, pix, game->img.datac[1]);
//	ft_printf("0 - %d - %d - %d\n", (game->ecrany - height) / 2, (game->ecrany + height) / 2, game->ecrany);
}
