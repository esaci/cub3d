#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <string.h>
#include <math.h>

/* OUBLIE PAS DE CHANGE LE MEMCPY PAR FTMEMCPY*/
/* Utilise fabs = valeur absolu */

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_release		3
# define X_EVENT_KEY_EXIT			17
# define KEY_ESC					53
# define KEY_Q						12
# define KEY_W						13
# define KEY_E						14
# define KEY_R						15
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define ROWS						11
# define COLS						15
# define WIDTH						COLS * 32
# define HEIGHT						ROWS * 32
# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

typedef struct s_img
{
	void		*imgptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_mlx
{
	void		*mlxptr;
	void		*win;
}				t_mlx;

typedef struct	s_game
{
	t_mlx	mlx;
	t_img	img;
	int		map[ROWS][COLS];
}				t_game;

void	window_init(t_game *game)
{
	game->mlx.mlxptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlxptr, WIDTH, HEIGHT, "ptit tableau tah elias");
	return;
}

void	map_init(t_game *game)
{
	int	map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

void	img_init(t_game *game)
{
	game->img.imgptr = mlx_new_image(game->mlx.mlxptr, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.imgptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

void	ftrectangle(t_game *game, int x, int y)
{
	int i;
	int j;

	x *= 32;
	y *= 32;
	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			game->img.data[(y + i) * WIDTH + x + j] = 0xFF000;
			j++;
		}
		i++;
	}
}

void	ftrectangleur(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while(j < COLS)
		{
			if (game->map[i][j] == 0)
				ftrectangle(game, j, i);
			j++;
		}
		i++;
	}
}

void	ftligne(t_game *game, double x1, double y1, double x2, double y2)
{
	double deltaX;
	double deltaY;
	double step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2- y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	ligneur(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLS)
	{
		ftligne(game, i * 32 - 1, 0, i * 32 - 1, HEIGHT);
		i++;
	}
	ftligne(game, COLS * 32 - 1, 0, COLS * 32 - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		ftligne(game, 0, j * 32, WIDTH, j * 32);
		j++;
	}
	ftligne(game, 0, ROWS * 32 - 1, WIDTH, ROWS * 32 - 1);
}

int		mappeur(t_game *game)
{
	ftrectangleur(game);
	ligneur(game);
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.win, game->img.imgptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;

	map_init(&game);
	window_init(&game);
	img_init(&game);

	mlx_loop_hook(game.mlx.mlxptr, &mappeur, &game);
	mlx_loop(game.mlx.mlxptr);
	return (0);
}
