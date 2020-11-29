void	drawrect(t_game	*game, int i, int height, int width, int dx, int dy)
{
	t_pix	pix;

	game->img.width[i] = width;
	game->img.height[i] = height;
	game->img.dx[i] = dx;
	game->img.dy[i] = dy;
	initmlxptr(game, i, game->img.width[i], game->img.height[i]);
	pix.x = 0;
	while (pix.x < game->img.height[i])
	{
		pix.y = 0;
		while (pix.y < game->img.width[i])
		{
			if ((pix.x >= 20 && pix.x <= height - 20 ) || (pix.y >= 10 && pix.y <= width - 10))
			{
				drawpix(game, i, pix, (unsigned char*)game->img.data[1]);
			}
			pix.y++;
		}
		pix.x++;
	}
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[i], game->img.dx[i], game->img.dy[i]);
	mlx_destroy_image(game->mlx.mlxptr, game->img.imgptr[i]);
}

void	divim(t_game *game, int i)
{
	int		count_w;
	int		count_h;

	count_h = 0;
	while (++count_h < game->img.height[i])
	{
		count_w = 0;
		while (++count_w < game->img.width[i] / 2)
		{
			if (count_w % 2)
			{
				ft_printf("%d \n", game->img.data[i][count_h * game->img.width[i] + count_w]);
			}
		}
	}
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[i], game->img.dx[i], game->img.dy[i]);
}

	else if (keycode == KEY_S)
	{
		game->img.dx[0] = 0;
		game->img.dy[0] = 0;
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr[0], game->img.dx[0] , game->img.dy[0]);
		game->hit = 2;
		game->step = 1;
	}

typedef struct	s_ray
{
	float		px;
	float		py;
	int			pdir;
	int			raydirx;
	int			raydiry;
	float		sidedistx;
	float		sidedisty;
	float		deltadistx;
	float		deltadisty;
	float		perpwalldist;
	int			lineheight;
	int			drawend;
	int			drawstart;
}				t_ray;

typedef struct	s_ray
{
	float		px;
	float		py;
	int			pdir;
	int			raydirx;
	int			raydiry;
	float		sidedistx;
	float		sidedisty;
	float		deltadistx;
	float		deltadisty;
	float		perpwalldist;
	int			lineheight;
	int			drawend;
	int			drawstart;
}				t_ray;
