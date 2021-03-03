/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:08:59 by esaci             #+#    #+#             */
/*   Updated: 2020/08/05 23:31:18 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putcharindent(char c, int fd, int *countu)
{
	write(fd, &c, 1);
	*countu = *countu + 1;
}

long int	ft_atoi2(const char *str, int *count)
{
	int				count2;
	long int		res;
	int				sign;

	count2 = 0;
	sign = 1;
	res = 0;
	if (str[count2] == '-')
		sign = -1;
	if (str[count2] == '+' || str[count2] == '-')
		count2++;
	while (str[count2] != '\0')
	{
		if (str[count2] >= '0' && str[count2] <= '9')
			res = (res * 10) + str[count2] - '0';
		if (!(str[count2] >= '0' && str[count2] <= '9'))
		{
			*count = *count + count2 + 1;
			return (res * sign);
		}
		count2++;
	}
	*count = *count + count2 + 1;
	return (res * sign);
}

char		*ft_strdupachar(const char *s1, char c)
{
	int			count;
	int			count2;
	char		*ptr;

	count = ft_strlen(s1);
	if (!(ptr = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count2 = 0;
	while (s1 && s1[count2] != '\0' && s1[count2] != c)
	{
		ptr[count2] = (char)s1[count2];
		count2++;
	}
	if (s1 && s1[count2] == c)
	{
		ptr[count2] = c;
		count2++;
	}
	ptr[count2] = '\0';
	return (ptr);
}
