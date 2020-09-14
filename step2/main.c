#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

int	touche_appuye(int keycode, int *j)
{
	if (keycode == 13)
		*j = *j + 1;
	else
		printf("pas lu\n");
	printf("%d", *j);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	int	i;
	int	j;

	j = 0;
	mlx = mlx_init();
	printf("j vaut %d", j);
	win = mlx_new_window(mlx, 800, 800, "travail");
	i = mlx_key_hook (win, &touche_appuye, &j);
	mlx_loop(mlx);
}
