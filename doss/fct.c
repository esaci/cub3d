/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:00:41 by esaci             #+#    #+#             */
/*   Updated: 2020/11/22 16:03:03 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

int	vision(int	keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_stop(game, "echap");
	}
	else if (keycode == KEY_Z)
	{
	}
	else if (keycode == KEY_Q)
	{
		game->pangle = (game->pangle + 10) % 360;
	}
	else if (keycode == KEY_S)
	{
	}
	else if (keycode == KEY_D)
	{
	}
	return(0);
}
