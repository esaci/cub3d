/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 13:42:54 by esaci             #+#    #+#             */
/*   Updated: 2020/08/08 23:41:48 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zerostructure(t_strct *e)
{
	e->point = 0;
	e->zero = 0;
	e->tiret = 0;
	e->espace = 0;
	e->hespace = 0;
	e->hpoint = 0;
	e->hzero = 0;
	e->htiret = 0;
	e->flagstrct = -1;
}

int			ft_testc(char f, char c)
{
	if (f != '0' && f != '-' && f != '.' && f != '*' && f != c)
		return ('S');
	if (ft_isdigit(f) && f != '0')
		return ('C');
	return ('R');
}

t_strct		readstrct(const char *formati, char c, va_list elias)
{
	t_strct	e;
	int		count;

	zerostructure(&e);
	count = 0;
	while (e.flagstrct == -1 && formati[count] != c)
	{
		if (formati[count] == ' ')
			count++;
		if (count == 0 && formati[count] != '0' && ft_isdigit(formati[count]))
			ft_chiffre(formati, &e, &count);
		if (formati[count] == '0')
			ft_zero(formati + count, &e, &count, elias);
		if (formati[count] == '-')
			ft_tiret(formati + count, &e, &count, elias);
		if (formati[count] == '.')
			ft_point(formati + count, &e, &count, elias);
		if (formati[count] == '*')
			ft_etoile(formati + count, &e, &count, elias);
		if (ft_testc(formati[count], c) == 'S')
			e.flagstrct = count;
		if (ft_testc(formati[count], c) == 'C')
			count++;
	}
	return (e);
}

void		ft_modif(t_strct *e, char c)
{
	if (e->htiret == 1)
		e->hzero = 0;
	if (e->hespace && e->espace < 0)
		e->tiret = -e->espace;
	if (!(e->htiret) && e->hzero && e->zero < 0)
	{
		e->htiret = 1;
		e->tiret = -e->zero;
		e->hzero = 0;
	}
	if (e->hpoint && c != 's' && e->point < 0)
		e->hpoint = 0;
	if (e->tiret < 0)
		e->tiret = -e->tiret;
}
