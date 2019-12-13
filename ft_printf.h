/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 16:10:06 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 15:53:05 by ybakker       ########   odam.nl         */
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
	char		convergions;
	char		flag_str;
	char		input_str;
	int			pre_c; //precision cordinate
	int			pre;//value
	int			pre_n_c;// n_c, so the vallue
	int			width_v;
	int			width_nb;
	int			min;
	int			zero;
	int			value; //remmeebr the value if its not 0, - . if - or 0, then its width
}				t_print;

int			ft_printf(const char *format, ...);
int			ft_printf_check(const char *format, va_list ap);
void		ft_end(t_print **print, va_list ap, const char *format);
void		struct_zero(t_print **print);

#endif

/*
check - and zero before the other flags, so numbers, * and .
remmeebr the numberS
*/
