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
	ft_memcpy(game->data[7] + 4 * game->ecranx * pix->y + pix->x * 4, couleur, sizeof(int));
}

void		drawrectimg(t_game	*game, int i, int ry)
{
	float		dist;
	int			height;
	t_pix		pix;

	dist = abs(g->ray.dist[1] * cos((g->ray.angle[1] - (float)g->pangle * 0.0174)));
	height = ceil(150 * g->ecrany / dist);
	pix.x = i;
	pix.flag = g->ray->x[ry];
	pix.y = 0;
	while (pix.y++ < (g->ecrany - height) / 2)
		drawpix(g, pix, g->datac[0]);
	while (pix.y++ < (g->ecrany))
		drawpix(g, pix, g->datac[1]);
}



void	drawrectimg(t_game	*game, int i, int ry)
{
	float		dist;
	int			height;
	t_tuple		img[2];

	dist = abs(game->ray.dist[i] * cos((r->t - (float)g->p_t * RAD)));
	height = ceil(WALL_COEFF * g->screen_y / dist);
	img[0].x = column;
	img[0].hit = hit;
	img[0].y = 0;
	while (img[0].y++ < (g->screen_y - height) / 2)
		put_pxl_to_img(g, &(img[0]), g->floor);
	while (img[0].y < (g->screen_y + height) / 2 && img[0].y++ < g->screen_y)
		put_txt_to_img(g, &(img[0]), r);
	while (img[0].y++ < (g->screen_y))
		put_pxl_to_img(g, &(img[0]), g->ceiling);
}
