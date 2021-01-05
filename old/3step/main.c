#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>


# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_release		3
# define X_EVENT_KEY_EXIT			17
# define KEY_ESC					65307
# define KEY_Q						12
# define KEY_W						113
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

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		i;
	int		j;
	int		k;

	mlx = mlx_init();
	j = 0;
	printf("j vaut %d\n", j);
	win = mlx_new_window(mlx, 800, 800, "travail");
	img = mlx_xpm_file_to_image(mlx, "wtf.xpm", &i, &k);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_destroy_image(mlx, img);
	printf("c fait");
	i = mlx_key_hook (win, &touche_appuye, &j);
	mlx_loop(mlx);
}
