/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:04:46 by esaci             #+#    #+#             */
/*   Updated: 2020/08/05 23:31:29 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chiffre(const char *formati, t_strct *e, int *countf)
{
	e->hespace = 1;
	e->espace = ft_atoi2(formati, countf);
	e->hzero = 0;
	if (e->htiret == 1)
		e->tiret = e->espace;
	*countf = *countf - 1;
}

void	ft_zero(const char *formati, t_strct *e, int *countf, va_list elias)
{
	if (formati[1] == '*')
	{
		e->zero = va_arg(elias, int);
		*countf = *countf + 2;
	}
	if (formati[1] != '*')
		e->zero = ft_atoi2(formati + 1, countf);
	e->hzero = 1;
}

void	ft_tiret(const char *formati, t_strct *e, int *countf, va_list elias)
{
	e->htiret = 1;
	if (formati[1] == '*')
	{
		e->tiret = va_arg(elias, int);
		*countf = *countf + 2;
	}
	if (formati[1] != '*')
		e->tiret = ft_atoi2(formati + 1, countf);
}

void	ft_point(const char *formati, t_strct *e, int *countf, va_list elias)
{
	int temp;

	if (formati[1] == '*')
	{
		e->point = va_arg(elias, int);
		*countf = *countf + 2;
		e->hpoint = 2;
	}
	if (formati[1] != '*')
	{
		temp = ft_atoi2(formati + 1, countf);
		if (e->hpoint != 2)
		{
			e->point = temp;
			e->hpoint = 1;
		}
	}
}

void	ft_etoile(const char *formati, t_strct *e, int *countf, va_list elias)
{
	e->espace = va_arg(elias, int);
	*countf = *countf + 1;
	e->hespace = 1;
	e->hzero = 0;
	if (e->htiret == 1)
		e->tiret = e->espace;
}
