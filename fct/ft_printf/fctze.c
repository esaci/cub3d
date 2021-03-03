/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctze.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:42:31 by esaci             #+#    #+#             */
/*   Updated: 2020/08/05 21:15:38 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fctze(const char *formati, va_list elias)
{
	char	*ptr;
	int		res;
	t_strct e;

	e = readstrct(formati + 1, '\0', elias);
	ft_modif(&e, '\0');
	ptr = ft_strdupachar(formati + e.flagstrct + 1, '\0');
	res = ft_strlen(ptr);
	ft_putstr_fd(ptr, 1);
	free(ptr);
	return (res);
}
