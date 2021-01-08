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
# define ROWS								60
# define COLS								60
# define SCREENWIDTH						720
# define SCREENHEIGHT						480
# define MAX_X								1920
# define MAX_Y								1020
# define MIN_X								320
# define MIN_Y								200
# define NBRDIMG							20
# define NBRCOUNT							10
# define TAILLEC							64
# define HAUTEURC							32

typedef struct		s_img
{
	void			*imgptr[NBRDIMG];
	unsigned char	*data[NBRDIMG];
	unsigned char	datac[2][4];
	char			*nom[NBRDIMG];
//	int				size_l[NBRDIMG];
//	int				bpp[NBRDIMG];
//	int				endian[NBRDIMG];
//	int				width[NBRDIMG];
//	int				height[NBRDIMG];
//	int				dx[NBRDIMG];
//	int				dy[NBRDIMG];
}					t_img;

typedef struct		s_mlx
{
	void			*mlxptr;
	void			*win;
}					t_mlx;

typedef struct		s_pix
{
//	int				x;
//	int				y;
//	int				count;
//	int				flag;
}					t_pix;

typedef struct		s_game
{
	t_mlx			mlx;
	t_img			img;
	int				c[NBRCOUNT];
	int				flag[2];
	int				ecranx; // resolution width
	int				ecrany; // resolution height
	int				mapx; // largeur map
	int				mapy; // hauteur map
	char			**map;
// ===========================================================================
	int				posy; // position sur la map map[y][:]
	int				posx; // position sur la map map[:][x]
	int				pangle; // p_t (s) angle ENWS :: 0 90 180 270
//	float			dx;
//	float			dy;
//	float			planex;
//	float			planey;
//	int				time;
//	int				oldtime;
//	float			camerax;
//	int				hit;
//	float			step;
//	int				stepx;
//	int				stepy;
//	int				side;
//	float			vise;
//	int				dstncs[SCREENWIDTH];
}					t_game;

typedef struct		s_ray
{
	float			angle[2]; // r->t C'est je pense l'angle de la camera dans la map
	int				x[2]; // La position de la camera dans la map
	int				y[2]; // La position de la camera dans la map

// La hauteur de la caméra HAUTEURC

// Le champ visuel de la camera 60degrés

// La taille de l’écran de projection

//	int				flag[2];
//	int				res[2];
//	float			dist[2];
}					t_ray;

void				raycat(t_game *game, t_ray *ray, int *x, int *w);
void				game_init(t_game game, int mode);
t_ray				ray_init(t_ray ray);
void				map_init(t_game *game);
void				window_init(t_game *game);
int					touche_appuye(int keycode, int *j);
int					vision(int	keycode, void *ptr);
void				drawrectimg(t_game	*game, int i, int j, int height, int width, int dx, int dy);
void				initmlxptr(t_game *game, int i, int width, int height);
void				initxpmptr(t_game *game, int i, char *str);
void				drawpix(t_game *game, int i, t_pix pix, unsigned char couleur[4]);
void				destroyer(t_game game, int j, ...);
void				modifdxdy(t_game *game, int i, int dx, int dy);
void				modifhw(t_game *game, int i, int height, int width);
int					rcx(t_game *game, t_ray *ray, int count);
int					setuped(t_game *game, t_ray *ray);
int					ft_signe(float x);
int					ft_max(int x, int y);
int					ft_min(int x, int y);
float				ft_dist(float x, float y);
void				drawcol(t_game *game, t_ray *ray, int col, int hit);
int					ft_only(char *line, char *only);
char				*ft_antiespace(char *line, t_game *game);
int					bordurerectangle(t_game *game);
int					nbrjoueurtligne(t_game *game, int i);
void				ft_rplayer(t_game *game);
int					ft_testc(char c, char *lettres);
void				ft_verif(t_game *game);
void				ft_chargement(t_game *game);
void				affichemap(t_game *game);
void				ft_depart(t_game *game);
#endif
