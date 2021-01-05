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

int	vision(int	keycode, void *ptr)
{
	t_game	*game;

	game = (t_game*)ptr;
	if (keycode == KEY_ESC)
	{
		destroyer(*game, 3, 10, 1, 2);
		if(game->flag == 1)
			destroyer(*game, 1, 3);
		exit(0);
	}
	else if (keycode == KEY_Z)
	{
	}
	else if (keycode == KEY_Q)
	{
	}
	else if (keycode == KEY_S)
	{
	}
	else if (keycode == KEY_D)
	{
	}
	return(0);
}
