/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctprc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 23:39:41 by esaci             #+#    #+#             */
/*   Updated: 2020/08/05 21:26:23 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prc(char *ptr, t_strct e)
{
	char	*str;

	str = ft_strdup(ptr);
	free(ptr);
	if (ft_strlen(str) != 0)
	{
		while (e.hpoint && e.point > ft_strlen(str))
			str = ft_cstrf(str, '0');
	}
	while (e.hzero && e.zero > ft_strlen(str))
	{
		if (!e.hpoint)
			str = ft_cstrf(str, '0');
		else
			str = ft_cstrf(str, ' ');
	}
	while (e.htiret && e.tiret > ft_strlen(str))
		str = ft_strcf(str, ' ');
	while (e.hespace && !e.htiret && e.espace > ft_strlen(str) && e.espace > 0)
		str = ft_cstrf(str, ' ');
	while (e.hespace && !e.htiret && -e.espace > ft_strlen(str) && e.espace < 0)
		str = ft_strcf(str, ' ');
	return (str);
}

int		fctprc(const char *formati, va_list elias)
{
	int		res;
	char	*ptr;
	t_strct e;

	e = readstrct(formati + 1, '%', elias);
	ft_modif(&e, '%');
	ptr = ft_strdup("%");
	if (e.flagstrct != -1)
	{
		free(ptr);
		ptr = ft_strdupachar(formati + e.flagstrct + 1, '%');
		ptr[ft_strlen(ptr) - 1] = 0;
	}
	else
		ptr = ft_prc(ptr, e);
	res = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (res);
}
