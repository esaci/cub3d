/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:36:09 by esaci             #+#    #+#             */
/*   Updated: 2020/08/09 20:22:02 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sn(t_strct e)
{
	char	*str;

	str = ft_strdup("");
	while (e.hzero && e.zero > ft_strlen(str))
	{
		if (e.hpoint)
			str = ft_cstrf(str, ' ');
		else
			str = ft_cstrf(str, '0');
	}
	while (e.htiret && e.tiret > ft_strlen(str))
		str = ft_strcf(str, ' ');
	while (e.hespace && e.espace > ft_strlen(str)
			&& e.espace > 0)
		str = ft_cstrf(str, ' ');
	while (e.hespace && -e.espace > ft_strlen(str)
			&& e.espace < 0)
		str = ft_strcf(str, ' ');
	return (str);
}

char	*ft_s(char *ptr, t_strct e)
{
	char	*str;

	str = ft_strdup(ptr);
	free(ptr);
	if (e.hpoint && e.point >= 0 && e.point < ft_strlen(str))
		str[e.point] = '\0';
	if (ft_strlen(str) == 0)
	{
		free(str);
		return (ft_sn(e));
	}
	while (e.hzero && e.zero > ft_strlen(str))
		str = ft_cstrf(str, e.hpoint ? ' ' : '0');
	while (e.htiret && e.tiret > ft_strlen(str))
		str = ft_strcf(str, ' ');
	while (e.hespace && e.espace > ft_strlen(str)
			&& e.espace > 0)
		str = ft_cstrf(str, ' ');
	while (e.hespace && -e.espace > ft_strlen(str)
			&& e.espace < 0)
		str = ft_strcf(str, ' ');
	return (str);
}

int		fcts(const char *formati, va_list elias)
{
	t_strct e;
	int		res;
	char	*ptr;

	e = readstrct(formati + 1, 's', elias);
	ft_modif(&e, 's');
	ptr = ft_strdupn(va_arg(elias, char*));
	if (e.flagstrct != -1)
	{
		free(ptr);
		ptr = ft_strdupachar(formati + e.flagstrct + 1, 's');
	}
	ptr = ft_s(ptr, e);
	res = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (res);
}
