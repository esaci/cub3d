/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 13:23:44 by esaci             #+#    #+#             */
/*   Updated: 2020/08/02 21:27:53 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c(char *str, t_strct e, int taille)
{
	int	count;
	int	ct2;

	count = 0;
	ct2 = taille;
	while (e.hzero && e.zero > ct2 && 1 + 0 * (ct2++))
		count += write(1, "0", 1);
	while (e.hpoint && e.point > ct2 && 1 + 0 * (ct2++))
		count += write(1, "0", 1);
	while (e.hespace && e.espace > ct2 && 1 + 0 * (ct2++))
		count += write(1, " ", 1);
	count += write(1, str, taille);
	while (e.hespace && e.espace < 0 && -e.espace > ct2 && 1 + 0 * (ct2++))
		count += write(1, " ", 1);
	while (e.htiret && e.tiret < 0 && -e.tiret > ct2
			&& 1 + 0 * (ct2++))
		count += write(1, " ", 1);
	while (e.htiret && e.tiret > ct2 && 1 + 0 * (ct2++))
		count += write(1, " ", 1);
	return (ct2);
}

int		fctc(const char *formati, va_list elias)
{
	char	c;
	t_strct e;
	char	*ptr;
	int		res;

	e = readstrct(formati + 1, 'c', elias);
	c = va_arg(elias, int);
	c = (unsigned char)c;
	if (!(ptr = malloc(sizeof(char) * 2)))
		return (0);
	ptr[0] = c;
	ptr[1] = '\0';
	if (e.flagstrct != -1)
	{
		free(ptr);
		ptr = ft_strdupachar(formati + e.flagstrct + 1, 'c');
	}
	res = ft_strlen(ptr);
	if (res == 0)
		res = ft_c(ptr, e, 1);
	else
		res = ft_c(ptr, e, res);
	free(ptr);
	return (res);
}
