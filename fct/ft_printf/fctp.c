/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:05:31 by esaci             #+#    #+#             */
/*   Updated: 2020/08/08 15:42:04 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_p(char *ptr, t_strct e)
{
	char	*str;
	int		count;

	str = ft_strdup(ptr);
	free(ptr);
	if (e.flagstrct != -1)
		return (str);
	if (ft_strlen(str) != 0)
	{
		while (e.hpoint && e.point > ft_strlen(str))
			str = ft_cstrf(str, '0');
	}
	str = ft_cstrf(str, 'x');
	str = ft_cstrf(str, '0');
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

int		fctp(const char *formati, va_list elias)
{
	long int	entier;
	char		*ptr;
	t_strct		e;
	long int	res;

	e = readstrct(formati + 1, 'p', elias);
	ft_modif(&e, 'p');
	entier = va_arg(elias, long int);
	if (entier == 0 && e.point == 0 && e.hpoint)
		ptr = ft_strdup("");
	else
		ptr = tradhexa(entier, 'a');
	if (e.flagstrct != -1)
	{
		free(ptr);
		ptr = ft_strdupachar(formati + e.flagstrct + 1, 'p');
	}
	ptr = ft_p(ptr, e);
	res = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (res);
}
