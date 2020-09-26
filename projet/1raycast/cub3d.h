#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <string.h>
#include <math.h>

/* OUBLIE PAS DE CHANGE LE MEMCPY PAR FTMEMCPY*/
/* Utilise fabs = valeur absolu */
/* test la div par 0*/
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
# define screenWIDTH				640
# define screenHEIGHT				480
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
	float	posx;
	float	posy;
	float	dx;
	float	dy;
	float	cameraX;
	int		mapX;
	int		mapY;
	int		hit;
	int		step;
	int		stepX;
	int		stepY;
	int		side;
}				t_game;

typedef struct	s_ray
{
	float	px;
	float	py;
	int		pdir;
	int		rayDirx;
	int		rayDiry;
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	float	perpWallDist;
	int		lineHeight;	
}				t_ray;
