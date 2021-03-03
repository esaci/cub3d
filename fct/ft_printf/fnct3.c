/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:02:24 by esaci             #+#    #+#             */
/*   Updated: 2020/08/05 22:38:07 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_calculn(char *dst, long int val)
{
	long int		val2;
	size_t			counti;

	counti = 0;
	if (val == -2147483648)
	{
		dst[counti++] = '8';
		val = 214748364;
	}
	if (val < 0)
	{
		val = (-1) * val;
	}
	val = val * 10;
	while ((val / 10) != 0 || counti == 0)
	{
		val = val / 10;
		val2 = val % 10;
		dst[counti++] = val2 + '0';
	}
	dst[counti] = '\0';
	return (dst);
}

char		*ft_itoansigne(int n)
{
	char		*dst;
	size_t		count;
	char		swotch;

	if (!(dst = malloc(sizeof(char) * 12)))
		return (NULL);
	dst = ft_calculn(dst, (long int)n);
	count = ft_strlen(dst) - 1;
	n = 0;
	while ((size_t)n < count)
	{
		swotch = dst[count];
		dst[count] = dst[n];
		dst[n] = swotch;
		n++;
		count--;
	}
	return (dst);
}

char		*tradhexa(long int entier, char lettre)
{
	char		res[101];
	long int	reste;
	int			k;

	k = 0;
	if (entier == 0)
		return (ft_strdup("0"));
	k = 0;
	res[100] = '\0';
	while (entier != 0)
	{
		reste = entier % 16;
		if (reste < 10)
			res[99 - k] = '0' + reste;
		else
			res[99 - k] = lettre + reste - 10;
		entier = entier / 16;
		k++;
	}
	res[99 - (k++)] = 23 + lettre;
	res[99 - (k++)] = '0';
	return (ft_strdupnbr(res + 100 - k + 2, 50));
}
