#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	int	x;
	int	i;
	int	j;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "travail");
	i = 0;
	j = 0;
	while (j < 400)
	{
		while (i < 300)
		{
			x = mlx_pixel_put(mlx, win, 400 + j, 400 + i, i + j);
			i++;
		}
		j++;
	}
	mlx_loop(mlx);
}
