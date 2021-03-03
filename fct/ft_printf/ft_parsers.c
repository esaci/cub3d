/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:48:36 by esaci             #+#    #+#             */
/*   Updated: 2020/08/09 18:06:18 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_definition(int (*ptrfct[250])(const char *, va_list))
{
	ptrfct[0] = &fctze;
	ptrfct['d'] = &fctd;
	ptrfct['p'] = &fctp;
	ptrfct['c'] = &fctc;
	ptrfct['s'] = &fcts;
	ptrfct['i'] = &fcti;
	ptrfct['u'] = &fctu;
	ptrfct['p'] = &fctp;
	ptrfct['x'] = &fctx;
	ptrfct['X'] = &fctxm;
	ptrfct['%'] = &fctprc;
}

int		testflag(char c)
{
	int		count;
	char	*flagz;

	count = 0;
	flagz = "cspdiuxX%";
	while (count < 9)
	{
		if (c == flagz[count])
			return ('E');
		count++;
	}
	return (0);
}

int		ft_parser(const char *formati, va_list elias, int *countu)
{
	static int		(*ptrfct[250])(const char *, va_list);
	int				count;

	count = 1;
	if (ptrfct['d'] == NULL)
		ft_definition(ptrfct);
	while (formati[count] && testflag(formati[count]) != 'E')
	{
		if (formati[count] == ' ')
			*countu += write(1, " ", 1);
		count++;
	}
	*countu = *countu + ptrfct[formati[count]](formati, elias);
	return (count + 1);
}
