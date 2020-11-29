/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:55:36 by esaci             #+#    #+#             */
/*   Updated: 2020/11/22 15:48:02 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"


# define KEY_ESC							65307
# define KEY_Z								122
# define KEY_Q								113
# define KEY_S								115
# define KEY_D								100
# define KEY_RIGHT							65363
# define KEY_LEFT							65361
# define KEY_UP								65362
# define KEY_DOWN							65364
# define ROWS								10
# define COLS								10
# define SCREENWIDTH						720
# define SCREENHEIGHT						480
# define NBRDIMG							ROWS * COLS + 10

typedef struct	s_img
{
	void		*imgptr[NBRDIMG];
	char		*data[NBRDIMG];
	int			size_l[NBRDIMG];
	int			bpp[NBRDIMG];
	int			endian[NBRDIMG];
	int			width[NBRDIMG];
	int			height[NBRDIMG];
	int			dx[NBRDIMG];
	int			dy[NBRDIMG];
}				t_img;

typedef struct	s_mlx
{
	void		*mlxptr;
	void		*win;
}				t_mlx;

typedef struct	s_pix
{
	int			x;
	int			y;
	int			count;
}				t_pix;

typedef struct	s_game
{
	t_mlx		mlx;
	t_img		img;
	int			map[ROWS][COLS];
	float		posx;
	float		posy;
	float		dx;
	float		dy;
	float		planex;
	float		planey;
	int			time;
	int			oldtime;
	float		camerax;
	int			mapx;
	int			mapy;
	int			hit;
	float		step;
	int			stepx;
	int			stepy;
	int			side;
	float		vise;
	int			flag;
	int			count;
}				t_game;

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

void			raycat(t_game *game, t_ray *ray, int *x, int *w);
t_game			game_init(t_game game);
t_ray			ray_init(t_ray ray);
void			var_init(t_game *game);
void			map_init(t_game *game);
void			window_init(t_game *game);
int				touche_appuye(int keycode, int *j);
int				vision(int	keycode, void *ptr);
void			drawrectimg(t_game	*game, int i, int j, int height, int width, int dx, int dy);
void			initmlxptr(t_game *game, int i, int width, int height);
void			initxpmptr(t_game *game, int i, char *str);
void			drawpix(t_game *game, int i, t_pix pix, unsigned char couleur[4]);
void			destroyer(t_game game, int j, ...);
void			modifdxdy(t_game *game, int i, int dx, int dy);
void			modifhw(t_game *game, int i, int height, int width);
#endif
