/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:25:24 by esaci             #+#    #+#             */
/*   Updated: 2021/01/06 12:25:29 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/cub3d.h"

int		ft_only(char *line, char *only)
{
	int		tab[255];
	int		i;

	i = 0;
	while(tab[i++])
		tab[i] = 0;
	i = 0;
	while(only[i++])
		tab[(int)only[i]]++;
	i = 0;
	while (line[i++])
	{
		if(tab[(int)line[i]] == 0)
			return(0);
	}
	return (1);
}

int		ft_contient(char *line, char *lettres)
{
	int 	count;
	int 	flag;
	char 	ptr[255];

	count = 0;
	while(count < 255)
		ptr[count++] = 0;
	count = 0;
	while (lettres[count])
		ptr[(int)lettres[count++]]++;
	flag = 0;
	count = 0;
	while(line[count])
	{
		if (ptr[(int)line[count]] != 0)
			flag++;
		count++;
	}
	return(flag);
}
