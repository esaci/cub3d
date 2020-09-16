#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <string.h>

/* OUBLIE PAS DE CHANGE LE MEMCPY PAR FTMEMCPY*/

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
	t_mlx	*mlx;
	t_img	img;
	int		map[ROWS][COLS];
}				t_game;

void	window_init(t_game *game)
{
	game->mlx->mlxptr = mlx_init();
	game->mlx->win = mlx_new_window(game->mlx->mlxptr, WIDTH, HEIGHT, "ptit tableau tah elias");
	return;
}

void	map_init(t_game *game)
{
	int	map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

int	main(void)
{
	t_game	game;

	map_init(&game);
	window_init(&game);
	return (0);
}
