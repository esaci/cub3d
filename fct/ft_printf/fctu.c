/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:26:03 by esaci             #+#    #+#             */
/*   Updated: 2020/08/09 17:27:54 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u(char *ptr, t_strct e)
{
	char	*str;

	str = ft_strdup(ptr);
	free(ptr);
	if (ft_strlen(str) != 0)
	{
		while (e.point > ft_strlen(str) && e.hpoint)
			str = ft_cstrf(str, '0');
	}
	while (e.zero > ft_strlen(str) && e.hzero)
	{
		if (e.hpoint)
			str = ft_cstrf(str, ' ');
		else
			str = ft_cstrf(str, '0');
	}
	while (e.tiret > ft_strlen(str) && e.htiret)
		str = ft_strcf(str, ' ');
	while (e.hespace && !e.htiret && e.espace > ft_strlen(str) && e.espace > 0)
		str = ft_cstrf(str, ' ');
	while (e.hespace && !e.htiret && -e.espace > ft_strlen(str) && e.espace < 0)
		str = ft_strcf(str, ' ');
	return (str);
}

char	*ft_exepy(char *ptr, unsigned int valeur)
{
	if (valeur == 4294967295)
		ptr = ft_strdup("4294967295");
	else
	{
		if ((int)valeur >= 0)
			ptr = ft_itoa(valeur);
		else
			ptr = ft_suuu(valeur);
	}
	return (ptr);
}

int		fctu(const char *formati, va_list elias)
{
	unsigned int	valeur;
	char			*ptr;
	t_strct			e;
	int				res;

	e = readstrct(formati + 1, 'u', elias);
	ft_modif(&e, 'u');
	valeur = va_arg(elias, unsigned int);
	if (valeur == 0 && e.point == 0 && e.hpoint)
		ptr = ft_strdup("");
	else
		ptr = ft_exepy(ptr, valeur);
	if (e.flagstrct != -1)
	{
		free(ptr);
		ptr = ft_strdupac(formati + e.flagstrct + 1, 'u');
	}
	ptr = ft_u(ptr, e);
	res = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (res);
}
