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
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define KEY_ESC							65307
# define KEY_Z								119
# define KEY_Q								97
# define KEY_S								115
# define KEY_D								100
# define KEY_RIGHT							65363
# define KEY_LEFT							65361
# define KEY_UP								65362
# define KEY_DOWN							65364
# define ROWS								60
# define COLS								60
# define SCREENWIDTH							720
# define SCREENHEIGHT							480
# define MAX_X								1920
# define MAX_Y								1020
# define MIN_X								320
# define MIN_Y								200
# define NBRDIMG							20
# define NBRCOUNT							20
# define HAUTEURC							32
# define HAUTEURMUR							150

typedef struct		s_img
{
	void			*imgptr[NBRDIMG];
	char			*data[NBRDIMG];
	unsigned char	datac[2][4];
	char			*nom[NBRDIMG];
	int				size_l[NBRDIMG];
	int				bpp[NBRDIMG];
	int				endian[NBRDIMG];
	int				width[NBRDIMG];
	int				height[NBRDIMG];
	int				dx[NBRDIMG];
	int				dy[NBRDIMG];
}					t_img;

typedef struct		s_mlx
{
	void			*mlxptr;
	void			*win;
}					t_mlx;

typedef struct		s_pix
{
	int				x;
	int				y;
	float			dist;
	float			angle;
	int				flag;
	char			carac;
}					t_pix;

typedef struct		s_sprite
{
	int				x;
	int				y;
	float			angle;
	float			dist;
}					t_sprite;

typedef struct		s_ray
{
	float			angle;
	int				x[2];
	int				y[2];
	int				flag[2];
	int				res[2];
	float			dist[2];
}					t_ray;

typedef struct		s_game
{
	t_mlx			mlx;
	t_img			img;
	t_ray			ray;
	int				c[NBRCOUNT];
	int				flag[4];
	int				ecranx;
	int				ecrany;
	int				mapx;
	int				mapy;
	char			**map;
	int				posy;
	int				posx;
	int				pangle;
}					t_game;

void				raycat(t_game *game, t_ray *ray, int *x, int *w);
void				game_init(t_game *game, int mode);
t_ray				ray_init(t_ray ray);
void				map_init(t_game *game, char *pave);
void				window_init(t_game *game);
int					touche_appuye(int keycode, int *j);
void				drawrectimg(t_game	*game, int i, int ry, int ryc);
void				drawrectimg2(t_game	*game, int i, int ry, int ryc);
void				initmlxptr(t_game *game, int i, int width, int height);
void				initxpmptr(t_game *game, int i, char *str);
void				drawpix(t_game *game, t_pix pix, unsigned char couleur[4]);
void				destroyer(t_game game, int j, ...);
void				modifdxdy(t_game *game, int i, int dx, int dy);
void				modifhw(t_game *game, int i, int height, int width);
void				rcx(t_game *g, int wr, char ix);
void				rcy(t_game *g, int wr, char ix);
int					ft_signe(float x);
int					ft_max(int x, int y);
int					ft_min(int x, int y);
float				ft_dist(float x, float y);
int					ft_only(char *line, char *only);
int					ft_contient(char *line, char *lettres);
char				*ft_antiespace(char *line, t_game *game);
void				bordurerectangle(t_game *game);
int					nbrjoueurtligne(t_game *game, int i);
void				ft_rplayer(t_game *game);
int					ft_testchar(char c, char *lettres);
void				ft_verif(t_game *game);
void				ft_chargement(t_game *game);
int					ft_depart(t_game *game);
void				ft_stop(t_game *game, char *error);
void				ft_rmap(t_game *game, char *pave);
void				ft_resolution(char *line, t_game *game);
void				ft_color(char *line, unsigned char *datac, t_game *game);
char				*ft_antiespace(char *line, t_game *game);
int					vision(int	keycode, t_game *game);
void				ft_dessin(t_game *game, float *dists);
void				ft_sprite(t_game *game, float *dists);
void				draw(t_game *game, t_pix *pix, int height, int ryc);
void				drawsprite(t_game *game, float *dists, t_sprite *s);
float				ft_abs(float x);
int					ft_bmp(t_game *game);
void				headbmp2(t_game *game, char *str, int i);
void				headbmp(t_game *game, char *str, int np);
void				swapbmp(t_game *game, char *str);
void				divid(char *str, int *i, int np);
int					ft_windz(t_game *game);

#endif
