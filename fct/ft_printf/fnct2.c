/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:42:53 by esaci             #+#    #+#             */
/*   Updated: 2020/08/08 18:34:35 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdupn(const char *s1)
{
	int		count;
	int		count2;
	char	*ptr;

	if (!(s1))
	{
		ptr = ft_strdup("(null)");
		return (ptr);
	}
	count = ft_strlen(s1);
	if (!(ptr = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count2 = 0;
	while (s1 && s1[count2] != '\0')
	{
		ptr[count2] = (char)s1[count2];
		count2++;
	}
	ptr[count2] = '\0';
	return (ptr);
}

char		*ft_strdupac(const char *s1, char c)
{
	int			count;
	int			count2;
	char		*ptr;

	count = ft_strlen(s1);
	if (!(ptr = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count2 = 0;
	while (s1[count2] != '\0' && s1[count2] != c)
	{
		ptr[count2] = s1[count2];
		count2++;
	}
	if (s1 && s1[count2] == c)
		ptr[count2++] = c;
	ptr[count2] = '\0';
	return (ptr);
}

char		*ft_cstrf(char *ptr, char c)
{
	char	*str;
	int		count;

	if (!(str = malloc(sizeof(char) * (ft_strlen(ptr) + 2))))
	{
		free(ptr);
		return (NULL);
	}
	count = 0;
	str[count] = c;
	while (ptr && ptr[count] != 0)
	{
		str[count + 1] = ptr[count];
		count++;
	}
	str[count + 1] = '\0';
	free(ptr);
	return (str);
}

char		*ft_strcf(char *ptr, char c)
{
	char		*str;
	int			count;

	if (!(str = malloc(sizeof(char) * (ft_strlen(ptr) + 2))))
	{
		free(ptr);
		return (NULL);
	}
	count = 0;
	while (ptr && ptr[count] != 0)
	{
		str[count] = ptr[count];
		count++;
	}
	str[count] = c;
	str[count + 1] = '\0';
	free(ptr);
	return (str);
}
