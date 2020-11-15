#include "../bibz/cub3d.h"

void	window_init(t_game *game)
{
	int i;
	int j;
	game->mlx.mlxptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlxptr, screenWIDTH, screenHEIGHT, "fenetre init");
	game->img.imgptr = mlx_xpm_file_to_image(game->mlx.mlxptr, "wtf.xpm", &i, &jode);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr, screenWIDTH / 10, screenHEIGHT / 10);
}

int		eliasabs(float x)
{
	if (x < 0)
		x = -x;
	return (x);
}

int	touche_appuye(int keycode, int *j)
{
	if (keycode == KEY_W)
		*j = *j + 1;
	else if(keycode == KEY_ESC)
		exit(0);
	return (0);
}
