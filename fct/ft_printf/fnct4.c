/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:04:26 by esaci             #+#    #+#             */
/*   Updated: 2020/08/09 19:00:19 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdupnbr(const char *s1, int nbr)
{
	char	*res;
	int		count;

	if (!(res = malloc(sizeof(char) * nbr)))
		return (NULL);
	count = 0;
	while (s1[count])
	{
		res[count] = (char)s1[count];
		count++;
	}
	res[count] = 0;
	return (res);
}

char		*ft_calculd(char *dst, long int val)
{
	long int		val2;
	size_t			counti;

	counti = 0;
	if (val == -2147483648)
	{
		dst[counti++] = '-';
		dst[counti++] = '8';
		val = 214748364;
	}
	if (val < 0)
	{
		dst[counti++] = '-';
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

char		*ft_suuu(unsigned int n)
{
	char		*dst;
	size_t		count;
	char		swotch;

	if (!(dst = malloc(sizeof(char) * 12)))
		return (NULL);
	dst = ft_calculd(dst, (long int)n);
	count = ft_strlen(dst) - 1;
	n = 0;
	if (dst[0] == '-')
		n++;
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
