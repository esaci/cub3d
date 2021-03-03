/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 13:55:13 by esaci             #+#    #+#             */
/*   Updated: 2020/08/08 23:44:34 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_strct
{
	int		point;
	int		tiret;
	int		zero;
	int		espace;
	int		hpoint;
	int		htiret;
	int		hzero;
	int		hespace;
	int		flagstrct;
}				t_strct;

char			*ft_cstrf(char *ptr, char c);
char			*ft_strcf(char *ptr, char c);

int				ft_printf(const char *format, ...);

t_strct			readstrct(const char *formati, char c, va_list elias);
void			ft_modif(t_strct *e, char c);

int				ft_parser(const char *formati, va_list elias, int *countu);

void			ft_chiffre(const char *formati, t_strct *e, int *countf);
void			ft_zero(const char *formati,
		t_strct *e, int *countf, va_list elias);
void			ft_tiret(const char *formati,
		t_strct *e, int *countf, va_list elias);
void			ft_point(const char *formati,
		t_strct *e, int *countf, va_list elias);
void			ft_etoile(const char *formati,
		t_strct *e, int *countf, va_list elias);

void			ft_putcharindent(char c, int fd, int *countu);
long int		ft_atoi2(const char *str, int *count);
char			*ft_strdupachar(const char *s1, char c);
char			*ft_strdupn(const char *s1);
char			*ft_strdupac(const char *s1, char c);
char			*ft_cstrf(char *ptr, char c);
char			*ft_strcf(char *ptr, char c);
char			*ft_calculn(char *dst, long int val);
char			*ft_itoansigne(int n);
char			*tradhexa(long int entier, char lettre);
char			*ft_strdupnbr(const char *s1, int nbr);
char			*unshexa(unsigned int entier, char lettre, int flag);
char			*ft_suuu(unsigned int n);

int				fctze(const char *formati, va_list elias);
int				fctd(const char *formati, va_list elias);
int				fctc(const char *formati, va_list elias);
int				fctp(const char *formati, va_list elias);
int				fcti(const char *formati, va_list elias);
int				fcts(const char *formati, va_list elias);
int				fctu(const char *formati, va_list elias);
int				fctp(const char *formati, va_list elias);
int				fctx(const char *formati, va_list elias);
int				fctxm(const char *formati, va_list elias);
int				fctprc(const char *formati, va_list elias);

#endif
