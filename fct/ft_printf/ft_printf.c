/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:05:56 by esaci             #+#    #+#             */
/*   Updated: 2020/08/08 17:01:45 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			countu;
	int			counti;
	int			taille;
	va_list		elias;

	va_start(elias, format);
	counti = 0;
	taille = ft_strlen(format);
	countu = 0;
	while (counti < taille)
	{
		if (format[counti] != '%')
		{
			ft_putcharindent(format[counti], 1, &countu);
			counti++;
		}
		if (format[counti] == '%')
			counti += ft_parser(format + counti, elias, &countu);
		if (counti >= taille)
			break ;
	}
	va_end(elias);
	return (countu);
}
