#include <stdio.h>
#include <stdlib.h>
#include "/home/elias/Bureau/cubed/cub3d/mlx/mlx.h"

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
	printf("j vaudrait %d\n", *j);
	return (0);
}

typedef struct s_img
{
	void		*imgptr;
	int			*data;
	int			size_l;
	int			bp;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_mlx
{
	void		*mlxptr;
	void		*win;
}				t_mlx;

int	main(void)
{
	t_mlx	mlx;
	t_img	img;
	int		count_w;
	int		count_h;

	mlx.mlxptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlxptr, 1200, 720, "travail");
	img.imgptr = mlx_xpm_file_to_image(mlx.mlxptr, "wtf.XPM", &img.width, &img.height);
/*	ca renvoie une chaine de charactere mais int a lair plus pratique */
	img.data = (int *)mlx_get_data_addr(img.imgptr, &img.bp, &img.size_l, &img.endian);
	count_h = -1;
	while (++count_h < img.height)
	{
		count_w = -1;
		while (++count_w < img.width / 2)
		{
			if (count_w % 2)
				img.data[count_h * img.width + count_w] = 0xFFFFFF;
			else
				img.data[count_h * img.width + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.win, img.imgptr, 0, 0);
	mlx_loop(mlx.mlxptr);
	return (0);
}
