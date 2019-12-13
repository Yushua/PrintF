/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 16:10:06 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 17:31:14 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_print
{
	int			begin;
	int			end;
	char		convergance;
	char		flag_str;
	char		input_str;
	int			pre_c; //precision cordinate
	int			pre;//value
	int			pre_n_c;// n_c, so the vallue
	int			width_v;
	int			width_nb; //width number
	int			min;
	int			zero;
	int			position;//position of 0 or -
	int			value;//remmember the value if its not 0, - . if - or 0, then its width
	int			value_c;
}				t_print;

int			ft_printf(const char *format, ...);
int			ft_printf_check(const char *format, va_list ap);
void		ft_print(t_print **print, va_list ap, int i, const char *format);
void		ft_min_zero(t_print **print, va_list ap, int i, const char *format);
void		ft_find_pre(t_print **print, va_list ap, int i, const char *format);
void		ft_print_f(t_print **print, va_list ap, int i, const char *format);
char		ft_convergance(t_print **print, int i, const char *format);
#endif

/*
check - and zero before the other flags, so numbers, * and .
remmeebr the numberS
*/
