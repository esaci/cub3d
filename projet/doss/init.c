#include "../bibz/cub3d.h"

t_game      game_init(t_game game)
{
    game.vise = 0;
	game.dx = 1;
	game.dy = 2;
    game.posx = 22;
	game.posy = 12;
}

t_ray       ray_init(t_ray ray)
{
	ray.px = 0;
	ray.py = 0.66;
}

void        var_init(int *time, int *oldtime, int *x, int *w)
{
    *time = 0;
	*oldtime = 0;
	*w = screenWIDTH;
	*x = 0;
}