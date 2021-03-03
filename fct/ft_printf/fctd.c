/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:17:26 by esaci             #+#    #+#             */
/*   Updated: 2020/08/08 15:43:01 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_d(char *ptr, t_strct e, int entier)
{
	char	*str;

	str = ft_strdup(ptr);
	free(ptr);
	if (ft_strlen(str) != 0)
	{
		while (e.hpoint && e.point > ft_strlen(str))
			str = ft_cstrf(str, '0');
		if (entier < 0 && e.hpoint)
			str = ft_cstrf(str, '-');
	}
	if (entier < 0 && !e.hpoint && (e.zero <= ft_strlen(str) || !e.hzero))
		str = ft_cstrf(str, '-');
	while (e.zero > ft_strlen(str) && e.hzero)
		str = ft_cstrf(str, e.hpoint ? ' ' : '0');
	if (entier < 0 && str[0] == '0')
		str[0] = '-';
	while (e.htiret && e.tiret > ft_strlen(str))
		str = ft_strcf(str, ' ');
	while (e.hespace && !e.htiret && e.espace > ft_strlen(str) && e.espace > 0)
		str = ft_cstrf(str, ' ');
	while (e.hespace && !e.htiret && -e.espace > ft_strlen(str) && e.espace < 0)
		str = ft_strcf(str, ' ');
	return (str);
}

int		fctd(const char *formati, va_list elias)
{
	t_strct e;
	int		res;
	char	*ptr;
	int		entier;

	e = readstrct(formati + 1, 'd', elias);
	ft_modif(&e, 'd');
	entier = va_arg(elias, int);
	if (e.hpoint && e.point == 0 && entier == 0)
		ptr = ft_strdup("");
	else
		ptr = ft_itoansigne(entier);
	if (e.flagstrct != -1)
	{
		free(ptr);
		ptr = ft_strdupac(formati + e.flagstrct + 1, 'd');
	}
	ptr = ft_d(ptr, e, entier);
	res = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (res);
}
