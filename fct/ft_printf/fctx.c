/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 21:44:39 by esaci             #+#    #+#             */
/*   Updated: 2020/08/09 18:57:57 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_exeph(char *ptr, long int valeur, int ma)
{
	if (valeur == 4294967295)
	{
		if (ma == 'A')
			ptr = ft_strdup("FFFFFFFF");
		else
			ptr = ft_strdup("ffffffff");
	}
	else
		ptr = tradhexa(valeur, ma);
	return (ptr);
}

char		*ft_x(char *ptr, t_strct e)
{
	int		count;
	char	*str;

	str = ft_strdup(ptr);
	free(ptr);
	if (ft_strlen(str) != 0)
	{
		while (e.hpoint && e.point > ft_strlen(str))
			str = ft_cstrf(str, '0');
	}
	while (e.hzero && e.zero > ft_strlen(str))
		str = ft_cstrf(str, e.hpoint ? ' ' : '0');
	while (e.htiret && e.tiret > ft_strlen(str))
		str = ft_strcf(str, ' ');
	while (e.hespace && !e.htiret && e.espace > ft_strlen(str) && e.espace > 0)
		str = ft_cstrf(str, ' ');
	while (e.hespace && !e.htiret && -e.espace > ft_strlen(str) && e.espace < 0)
		str = ft_strcf(str, ' ');
	return (str);
}

int			fctx(const char *formati, va_list elias)
{
	long int	res;
	char		*ptr;
	long int	valeur;
	t_strct		e;

	e = readstrct(formati + 1, 'x', elias);
	ft_modif(&e, 'x');
	valeur = va_arg(elias, unsigned int);
	if (valeur == 0 && e.hpoint && e.point == 0)
		ptr = ft_strdup("");
	else
		ptr = ft_exeph(ptr, valeur, 'a');
	if (e.flagstrct != -1)
	{
		free(ptr);
		ptr = ft_strdupachar(formati + e.flagstrct + 1, 'x');
	}
	ptr = ft_x(ptr, e);
	res = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (res);
}

int			fctxm(const char *formati, va_list elias)
{
	long int	res;
	char		*ptr;
	long int	valeur;
	t_strct		e;

	e = readstrct(formati + 1, 'X', elias);
	ft_modif(&e, 'X');
	valeur = va_arg(elias, unsigned int);
	if (valeur == 0 && e.hpoint && e.point == 0)
		ptr = ft_strdup("");
	else
		ptr = ft_exeph(ptr, valeur, 'A');
	if (e.flagstrct != -1)
	{
		free(ptr);
		ptr = ft_strdupachar(formati + e.flagstrct + 1, 'X');
	}
	ptr = ft_x(ptr, e);
	res = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (res);
}
