#include "../bibz/cub3d.h"

void    raycat(t_game *game, t_ray *ray, int *x, int *w)
{
// calcul pour chaque ligne verticale, ca commence a la (ray.px, ray.py)
// cameraX est la projection de ray.px sur le plan, avec ce calcul tout a gauche -1, milieu 0 et a droite a gauche
// 
	while (x < w)
	{
		game.cameraX = 2 * x / w - 1;
		ray.rayDirx = game.dx + ray.px * game.cameraX;
		ray.rayDiry = game.dy + ray.py * game.cameraX;
		x++;
	}
	// mapX et et mapY rpz le carre ou est lobjet quon ray c donc entier
	// sideDistX et sideDistY distance entre lobjet et le premiere entier x ou entier y
	// deltaDistX et deltaDistY c d'un entier x et y a l'autre entier
	game.mapX = (int)(game.posx);
	game.mapY = (int)(game.posy);
	ray.deltaDistX = eliasabs(1 / ray.rayDirx);
	ray.deltaDistY = eliasabs(1 / ray.rayDiry);
	game.hit = 0;

	if (ray.rayDirx < 0)
	{                                                                                     
		game.step = -1;
		ray.sideDistX = (game.posx - game.mapX) * ray.deltaDistX;
	}
	else
	{
		game.stepX = 1;
		ray.sideDistX = (game.mapX + 1 - game.posx) * ray.deltaDistX;
	}
	if (ray.rayDiry < 0)
	{
		game.step = -1;
		ray.sideDistY = (game.posy - game.mapY) * ray.deltaDistY;
	}
	else
	{
		game.stepY = 1;
		ray.sideDistY = (game.mapY + 1 - game.posy) * ray.deltaDistY;
	}
// tant qu'n a rien tape, on avance, si on tape tout stop et side vaut 0 si on bouge en X sinon 1 et bouge en Y
	while (game.hit == 0)
	{
		if (ray.sideDistX < ray.sideDistY)
		{
			ray.sideDistX += ray.deltaDistX;
			game.mapX += game.stepX;
			game.side = 0;
		}
		else {
			ray.sideDistY += ray.deltaDistY;
			game.mapY += game.stepY;
			game.side = 1;
		}
		if (game.map[game.mapX][game.mapY] > 0)
			game.hit = 1;
	}
// perpWallDist taille de la ligne perpendiculaire a mon plan de camera et touche H, le point qui est raycast, MTN DIFF X ET Y ?
	if(game.side == 0)
		ray.perpWallDist = (game.mapX - game.posx + (1 - game.stepX) / 2) / ray.rayDirx;
	else
		ray.perpWallDist = (game.mapY - game.posy + (1 - game.stepY) / 2) / ray.rayDiry;
// taille de la ligne direct entre la pos et le point qui est raycast
	ray.lineHeight = (int)(game.vise / ray.perpWallDist);
	ray.drawstart = -ray.lineHeight / 2 + game.vise / 2;
	if (ray.drawstart < 0)
		ray.drawstart = 0;
	ray.drawend = ray.lineHeight / 2 + game.vise / 2;
	if (ray.drawend < 0)
		ray.drawend = game.vise - 1;
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	
}