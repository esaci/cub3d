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

void	drawpix(t_game *game, int i, t_pix pix, unsigned char couleur[4])
{
	ft_memcpy(game->img.data[i] + 4 * pix.y * game->img.width[i] + pix.x * 4, couleur, sizeof(int));
}

void	drawrectimg(t_game	*game, int i, int j, int height, int width, int dx, int dy)
{
	t_pix	pix;

	/* faire un rectangle dans une fenetre de taille height width et place (dx,dy) dans la fenetre*/
	game->img.width[i] = width;
	game->img.height[i] = height;
	game->img.dx[i] = dx;
	game->img.dy[i] = dy;
	pix.y = 0;
	initmlxptr(game, i, game->img.width[i], game->img.height[i]);
	while(pix.y < height)
	{
		pix.x = 0;
		pix.count = game->img.width[j] * pix.y;
		while(pix.x < width)
		{
			if(pix.y == (height-1) || pix.y == 0 || pix.x == 0 || pix.x == (width - 1))
			{
				drawpix(game, i, pix, (unsigned char*)game->img.data[j]);
			}
			else
			{
				drawpix(game, i, pix, (unsigned char*)game->img.data[j] + pix.count * 4);
			}
			pix.count = pix.count + 1;
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[i], game->img.dx[i], game->img.dy[i]);
	mlx_destroy_image(game->mlx.mlxptr, game->img.imgptr[i]);
}
