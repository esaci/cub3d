#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>


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

int	touche_appuye(int keycode, int *j)
{
	if (keycode == KEY_W)
		*j = *j + 1;
	else if(keycode == KEY_ESC)
		exit(0);
		printf("pas lu\n");
	printf("j vaudrait %d\n", *j);
	return (0);
}

typedef struct s_img
{
	void		*imgptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlxptr;
	void		*win;
}				t_mlx;

int	main(void)
{
	t_mlx	*mlx;
	t_img	img;
	int		count_w;
	int		count_h;

	mlx->mlxptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlxptr, 1200, 720, "travail");
	img.imgptr = mlx_xpm_file_to_image(mlx->mlxptr, "wtf.xpm", &count_w, &count_h);
	mlx_put_image_to_window(mlx->mlxptr, mlx->win, img.imgptr, 40, 40); 
	mlx_loop(mlx->mlxptr);
	return (0);
}
